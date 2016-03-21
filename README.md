# X509GetPubkeyLeak

C project demonstrate memory leak caused by calling an X509_get_pubkey function.

-OpenSSL static librarie version 1.0.2g.
-GCC command: gcc -g -gdwarf-2 -arch x86_64 -I /X509GetPubkeyLeak/include -L /X509GetPubkeyLeak/lib -o LeakEmulator main.c PKLLeakEmulator.c PKLX509Certificate.c -lssl -lcrypto

-Valgrind-3.11.0
valgrind --tool=memcheck --leak-check=yes --leak-check=full /X509GetPubkeyLeak/LeakEmulator

==21754== LEAK SUMMARY:
==21754==    definitely lost: 448 bytes in 5 blocks
==21754==    indirectly lost: 1,600 bytes in 35 blocks
==21754==      possibly lost: 0 bytes in 0 blocks
==21754==    still reachable: 16,426 bytes in 26 blocks
==21754==         suppressed: 21,777 bytes in 186 blocks
==21754== Reachable blocks (those to which a pointer was found) are not shown.
==21754== To see them, rerun with: --leak-check=full --show-leak-kinds=all
==21754== 
==21754== For counts of detected and suppressed errors, rerun with: -v
==21754== Use --track-origins=yes to see where uninitialised values come from
==21754== ERROR SUMMARY: 2487 errors from 47 contexts (suppressed: 18 from 18)