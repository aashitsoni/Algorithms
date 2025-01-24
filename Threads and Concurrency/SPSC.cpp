#include <atomic>
#include <iostream>
#include <string>
#include <thread>
#include <vector>

const int N = 1; // how many concurrent readers are needed.
std::atomic<int> mylock( 1 );
std::vector<int> msgs;


void consumer() {
    int value;
    std::chrono::microseconds sl( 1 );
    while(1) {

        // lock 
        if( std::atomic_fetch_sub( &mylock, 1 ) > 0 ) {
            // read
            if( !msgs.empty() ) {
                value = msgs.front();
                msgs.pop_back();
                std::cout << "Got message: " << value << std::endl;
                if( value == 0 ) {
                    break;
                }
            }
            // unlock
            std::atomic_fetch_add( &mylock, 1 );
            
            // pause for small amount
            std::this_thread::sleep_for( sl );
        } else {
            std::atomic_fetch_add( &mylock, 1 );
        }
    }
    std::cout << "Completed consumer Thread" << std::endl;

}

void producer() {
    int nMessages = 25;
    std::chrono::microseconds sl( 1 );

    while( 1 ) {

        // lock 
        if( std::atomic_fetch_sub( &mylock, 2 ) == 1 ) {
           // write
            --nMessages;
            msgs.push_back( nMessages );
            std::cout << "Send Message: " << nMessages << std::endl;
            // unlock
            std::atomic_fetch_add( &mylock, 2 );

            // pause for a bit
            std::this_thread::sleep_for( sl );
            if( nMessages == 0 ) {
                break;
            }
        } else {
            std::atomic_fetch_add( &mylock, 2 );
        }
    }
    std::cout << "Completed producer thread" << std::endl;
}

int main( int argc, char** argv )
{
    std::vector<std::thread> threadVec;
    threadVec.emplace_back( producer );
    threadVec.emplace_back( consumer );
    for( auto& t: threadVec ) {
        t.join();
    }
    std::cout << "Exited" << std::endl;
    return 0;
}