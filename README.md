# shared_memory
Example of using shared memory with semaphores for IPC

There is one `Producer` and several `Consumer`s. 

Each one of them runs in a different process.

The `Producer` produces a random number and puts it in the shared memory.

The `Consumer` 
1. copy the random number to a local variable.
2. frees the shared memory.
3. checks if this number is prime async.

The write and read from the shared memory are protected by semaphores.

# Usage
Tested on Ubuntu 24.04

# Compilation
Assumes g++ is installed
```
chmod +x ./compile.sh
./compile.sh
```

# Run
```
chmod +x ./run.sh
./run.sh
```

# Kill
```
chmod +x ./kill.sh
./kill.sh
```

# Expected logs
```
Producer 0 attached the memory to its virtual space...
Producer 0 iteration #      0 value   5482698876454931888
Consumer 2 has received a shared memory...
Consumer 2 has attached the shared memory to it's virtual memory space...
Consumer 2 iteration #      0 number  5482698876454931888 is not prime
Producer 0 iteration #      1 value  12835134432194230583
Consumer 3 has received a shared memory...
Consumer 3 has attached the shared memory to it's virtual memory space...
Consumer 3 iteration #      0 number 12835134432194230583 is not prime
Producer 0 iteration #      2 value   2958876851924856035
Consumer 2 iteration #      1 number  2958876851924856035 is not prime
Producer 0 iteration #      3 value  17614912136905895761
Producer 0 iteration #      4 value   1888455964812464599
Producer 0 iteration #      5 value   5708310635820313874
Consumer 3 iteration #      1 number  1888455964812464599 is not prime
Consumer 3 iteration #      2 number  5708310635820313874 is not prime
Producer 0 iteration #      6 value   9534260160175479655
Consumer 3 iteration #      3 number  9534260160175479655 is not prime
Producer 0 iteration #      7 value   2308941604859248940
Consumer 3 iteration #      4 number  2308941604859248940 is not prime
Producer 0 iteration #      8 value  17467920828709886430
Consumer 3 iteration #      5 number 17467920828709886430 is not prime
Producer 0 iteration #      9 value  15545179353524568413
Producer 0 iteration #     10 value    501914649978567336
Consumer 1 has received a shared memory...
Consumer 1 has attached the shared memory to it's virtual memory space...
Consumer 1 iteration #      0 number   501914649978567336 is not prime
Producer 0 iteration #     11 value   3014685672319467598
Consumer 1 iteration #      1 number  3014685672319467598 is not prime
Producer 0 iteration #     12 value   4364109314340880384
Consumer 1 iteration #      2 number  4364109314340880384 is not prime
Producer 0 iteration #     13 value  12013748120121626791
Consumer 1 iteration #      3 number 12013748120121626791 is not prime
Producer 0 iteration #     14 value  10364036877383956123
Consumer 1 iteration #      4 number 10364036877383956123 is not prime
Producer 0 iteration #     15 value  11036861606816867290
Consumer 1 iteration #      5 number 11036861606816867290 is not prime
Producer 0 iteration #     16 value   2763504112704597859
Consumer 1 iteration #      6 number  2763504112704597859 is not prime
Producer 0 iteration #     17 value  16036886365726651370
Consumer 1 iteration #      7 number 16036886365726651370 is not prime
Producer 0 iteration #     18 value  14340139660327554666
Consumer 1 iteration #      8 number 14340139660327554666 is not prime
Producer 0 iteration #     19 value   8994649564184197719
Consumer 1 iteration #      9 number  8994649564184197719 is not prime
Producer 0 iteration #     20 value   4887635994602733324
Consumer 1 iteration #     10 number  4887635994602733324 is not prime
Producer 0 iteration #     21 value  18352489287769723664
Consumer 1 iteration #     11 number 18352489287769723664 is not prime
Producer 0 iteration #     22 value  12087978304630359111
Consumer 1 iteration #     12 number 12087978304630359111 is not prime
Producer 0 iteration #     23 value  14132266451831612639
Consumer 1 iteration #     13 number 14132266451831612639 is not prime
Producer 0 iteration #     24 value  15970902506297527090
Consumer 1 iteration #     14 number 15970902506297527090 is not prime
Producer 0 iteration #     25 value  11117636177642651720
Consumer 1 iteration #     15 number 11117636177642651720 is not prime
Producer 0 iteration #     26 value   3638778183989598285
Consumer 1 iteration #     16 number  3638778183989598285 is not prime
Producer 0 iteration #     27 value   1571424262708127542
Consumer 1 iteration #     17 number  1571424262708127542 is not prime
Producer 0 iteration #     28 value   6013536397998239803
Consumer 1 iteration #     18 number  6013536397998239803 is not prime
Producer 0 iteration #     29 value   6688226706166301432
Consumer 1 iteration #     19 number  6688226706166301432 is not prime
Producer 0 iteration #     30 value    163757569874420306
Consumer 1 iteration #     20 number   163757569874420306 is not prime
Producer 0 iteration #     31 value  10647622387933400745
Consumer 1 iteration #     21 number 10647622387933400745 is not prime
Producer 0 iteration #     32 value     77609613926004623
Producer 0 iteration #     33 value   2228202789125542828
Consumer 1 iteration #     22 number    77609613926004623 is not prime
Consumer 1 iteration #     23 number  2228202789125542828 is not prime
Producer 0 iteration #     34 value  14780832503064401938
Consumer 1 iteration #     24 number 14780832503064401938 is not prime
Producer 0 iteration #     35 value   8406069110651164124
Consumer 1 iteration #     25 number  8406069110651164124 is not prime
Producer 0 iteration #     36 value   2368705011842112328
Consumer 1 iteration #     26 number  2368705011842112328 is not prime
Producer 0 iteration #     37 value  13186968010639916989
Producer 0 iteration #     38 value   8310400911208242587
Consumer 1 iteration #     27 number 13186968010639916989 is prime
Consumer 1 iteration #     28 number  8310400911208242587 is not prime
Producer 0 iteration #     39 value   4006334363317896133
Producer 0 iteration #     40 value  18383301211229263205
Consumer 1 iteration #     29 number  4006334363317896133 is not prime
Consumer 1 iteration #     30 number 18383301211229263205 is not prime
Producer 0 iteration #     41 value   2189306944578839506
Consumer 1 iteration #     31 number  2189306944578839506 is not prime
Producer 0 iteration #     42 value   5561587873167857188
Consumer 1 iteration #     32 number  5561587873167857188 is not prime
Producer 0 iteration #     43 value  10968321864896746738
Consumer 1 iteration #     33 number 10968321864896746738 is not prime
Producer 0 iteration #     44 value  15269128229891799433
Producer 0 iteration #     45 value   3455824617593558263
Consumer 1 iteration #     34 number 15269128229891799433 is not prime
Consumer 1 iteration #     35 number  3455824617593558263 is not prime
Producer 0 iteration #     46 value   9187101064444542247
Consumer 1 iteration #     36 number  9187101064444542247 is not prime
Producer 0 iteration #     47 value  11249630001646367135
Consumer 1 iteration #     37 number 11249630001646367135 is not prime
Producer 0 iteration #     48 value  13734399740029454604
Consumer 1 iteration #     38 number 13734399740029454604 is not prime
Producer 0 iteration #     49 value   8650933682872190577
Consumer 1 iteration #     39 number  8650933682872190577 is not prime
Producer 0 iteration #     50 value   7074365758701589631
Producer 0 iteration #     51 value  15164769597611200231
Consumer 1 iteration #     40 number  7074365758701589631 is not prime
Consumer 1 iteration #     41 number 15164769597611200231 is not prime
Consumer 1 iteration #     42 number  3850435439013469458 is not prime
Producer 0 iteration #     52 value   3850435439013469458
Producer 0 iteration #     53 value  18287792308518216201
Producer 0 iteration #     54 value  11614461420060051096
Consumer 1 iteration #     43 number 18287792308518216201 is not prime
Consumer 1 iteration #     44 number 11614461420060051096 is not prime
Producer 0 iteration #     55 value   2091181103158083848
Consumer 1 iteration #     45 number  2091181103158083848 is not prime
Producer 0 iteration #     56 value  15401950894925667391
Consumer 1 iteration #     46 number 15401950894925667391 is not prime
Producer 0 iteration #     57 value  10670543950445017751
Consumer 1 iteration #     47 number 10670543950445017751 is not prime
Producer 0 iteration #     58 value  14730332734242239471
Consumer 1 iteration #     48 number 14730332734242239471 is not prime
Producer 0 iteration #     59 value  17341712167948885124
Consumer 1 iteration #     49 number 17341712167948885124 is not prime
Producer 0 iteration #     60 value  17334444357834427518
Consumer 1 iteration #     50 number 17334444357834427518 is not prime
Producer 0 iteration #     61 value  17776361955228961041
Consumer 1 iteration #     51 number 17776361955228961041 is not prime
Producer 0 iteration #     62 value  13561353791130770444
Consumer 1 iteration #     52 number 13561353791130770444 is not prime
Producer 0 iteration #     63 value   9151413693270793128
Consumer 1 iteration #     53 number  9151413693270793128 is not prime
Producer 0 iteration #     64 value  15331624835279203601
Consumer 1 iteration #     54 number 15331624835279203601 is not prime
Producer 0 iteration #     65 value  13415048997704584846
Consumer 1 iteration #     55 number 13415048997704584846 is not prime
Producer 0 iteration #     66 value  16521345573524496904
Consumer 1 iteration #     56 number 16521345573524496904 is not prime
Producer 0 iteration #     67 value  14622718315983681538
Consumer 1 iteration #     57 number 14622718315983681538 is not prime
Producer 0 iteration #     68 value   4496942490879008694
Consumer 1 iteration #     58 number  4496942490879008694 is not prime
Producer 0 iteration #     69 value   6462496700333185042
Consumer 1 iteration #     59 number  6462496700333185042 is not prime
Producer 0 iteration #     70 value   9512187902445837399
Consumer 1 iteration #     60 number  9512187902445837399 is not prime
Producer 0 iteration #     71 value  10564652541757071614
Consumer 1 iteration #     61 number 10564652541757071614 is not prime
Producer 0 iteration #     72 value   5894367818267158888
Consumer 1 iteration #     62 number  5894367818267158888 is not prime
Consumer 1 iteration #     63 number  8904507411112373622 is not prime
Producer 0 iteration #     73 value   8904507411112373622
Producer 0 iteration #     74 value   5323286272135782019
Producer 0 iteration #     75 value  12000506377089578656
Consumer 1 iteration #     64 number  5323286272135782019 is prime
Consumer 1 iteration #     65 number 12000506377089578656 is not prime
Consumer 1 iteration #     66 number  9348196152510480530 is not prime
Producer 0 iteration #     76 value   9348196152510480530
Producer 0 iteration #     77 value   8826007577472858947
Producer 0 iteration #     78 value   3851980646699213029
Consumer 1 iteration #     67 number  8826007577472858947 is not prime
Consumer 1 iteration #     68 number  3851980646699213029 is not prime
Producer 0 iteration #     79 value  13986393631244533812
Producer 0 iteration #     80 value   7935660853445277343
Consumer 1 iteration #     69 number 13986393631244533812 is not prime
Consumer 1 iteration #     70 number  7935660853445277343 is not prime
Producer 0 iteration #     81 value   2926075023568186528
Consumer 1 iteration #     71 number  2926075023568186528 is not prime
Producer 0 iteration #     82 value  15388723001531467984
Consumer 1 iteration #     72 number 15388723001531467984 is not prime
Producer 0 iteration #     83 value  11216779406398595665
Consumer 1 iteration #     73 number 11216779406398595665 is not prime
Producer 0 iteration #     84 value  13613565934822097780
Consumer 1 iteration #     74 number 13613565934822097780 is not prime
Producer 0 iteration #     85 value  10618617426027575947
Consumer 1 iteration #     75 number 10618617426027575947 is not prime
Producer 0 iteration #     86 value  15060707720666792675
Consumer 1 iteration #     76 number 15060707720666792675 is not prime
Producer 0 iteration #     87 value  13413426742206659045
Consumer 1 iteration #     77 number 13413426742206659045 is not prime
Producer 0 iteration #     88 value  14158434077775433619
Producer 0 iteration #     89 value   5392830684238212395
Consumer 1 iteration #     78 number 14158434077775433619 is not prime
Consumer 1 iteration #     79 number  5392830684238212395 is not prime
Producer 0 iteration #     90 value  16055485760320614707
Producer 0 iteration #     91 value  10716408927228134716
Consumer 1 iteration #     80 number 16055485760320614707 is not prime
Consumer 1 iteration #     81 number 10716408927228134716 is not prime
Producer 0 iteration #     92 value   1565664477972134420
Consumer 1 iteration #     82 number  1565664477972134420 is not prime
Producer 0 iteration #     93 value  15796081587463799891
Consumer 1 iteration #     83 number 15796081587463799891 is not prime
Producer 0 iteration #     94 value  12672462769981617533
Consumer 1 iteration #     84 number 12672462769981617533 is not prime
Producer 0 iteration #     95 value   2455746526324359182
Consumer 1 iteration #     85 number  2455746526324359182 is not prime
Producer 0 iteration #     96 value  13628355411392024027
Consumer 1 iteration #     86 number 13628355411392024027 is not prime
Producer 0 iteration #     97 value   2970455394691951488
Consumer 1 iteration #     87 number  2970455394691951488 is not prime
Producer 0 iteration #     98 value  11668437392613362724
Consumer 1 iteration #     88 number 11668437392613362724 is not prime
Producer 0 iteration #     99 value  15802822536187436033
Producer 0 iteration #    100 value   3176956739203202303
Consumer 1 iteration #     89 number 15802822536187436033 is not prime
Producer 0 iteration #    101 value  12537573013353700392
Consumer 1 iteration #     90 number  3176956739203202303 is not prime
Consumer 1 iteration #     91 number 12537573013353700392 is not prime
Producer 0 iteration #    102 value   6003571168899455377
Producer 0 iteration #    103 value   1578123366172025228
Consumer 1 iteration #     92 number  6003571168899455377 is not prime
Consumer 1 iteration #     93 number  1578123366172025228 is not prime
Producer 0 iteration #    104 value   5588164788721984272
Consumer 1 iteration #     94 number  5588164788721984272 is not prime
Producer 0 iteration #    105 value   4642472228976002749
Producer 0 iteration #    106 value   3467780903220219832
Consumer 1 iteration #     95 number  4642472228976002749 is not prime
Consumer 1 iteration #     96 number  3467780903220219832 is not prime
Producer 0 iteration #    107 value  14008227981924044893
Producer 0 iteration #    108 value   4627807918276155146
Consumer 3 iteration #      6 number 15545179353524568413 is prime
Consumer 3 iteration #      7 number  4627807918276155146 is not prime
Producer 0 iteration #    109 value  15421991744170097461
Producer 0 iteration #    110 value  15782007851160680578
Consumer 2 iteration #      2 number 17614912136905895761 is prime
Consumer 2 iteration #      3 number 15782007851160680578 is not prime
Consumer 2 iteration #      4 number 11492887534506070554 is not prime
Producer 0 iteration #    111 value  11492887534506070554
Producer 0 iteration #    112 value  15842288155631759533
Consumer 2 iteration #      5 number 15842288155631759533 is not prime
Producer 0 iteration #    113 value  15848191611697376876
Consumer 2 iteration #      6 number 15848191611697376876 is not prime
Producer 0 iteration #    114 value  15249955520369072404
Consumer 2 iteration #      7 number 15249955520369072404 is not prime
Producer 0 iteration #    115 value   1068075302014732929
Consumer 2 iteration #      8 number  1068075302014732929 is not prime
Producer 0 iteration #    116 value   6733316935936375488
Consumer 2 iteration #      9 number  6733316935936375488 is not prime
Producer 0 iteration #    117 value  10982601735122566592
Consumer 2 iteration #     10 number 10982601735122566592 is not prime
Producer 0 iteration #    118 value  15273225559198810406
Consumer 2 iteration #     11 number 15273225559198810406 is not prime
Producer 0 iteration #    119 value  17954759741887453847
Consumer 2 iteration #     12 number 17954759741887453847 is not prime
Producer 0 iteration #    120 value  12257344409191506800
Consumer 2 iteration #     13 number 12257344409191506800 is not prime
Producer 0 iteration #    121 value   7428810335586446426
Consumer 2 iteration #     14 number  7428810335586446426 is not prime
Producer 0 iteration #    122 value  17274762567973374000
Consumer 2 iteration #     15 number 17274762567973374000 is not prime
Producer 0 iteration #    123 value   7020981202909075000
Consumer 2 iteration #     16 number  7020981202909075000 is not prime
Producer 0 iteration #    124 value   4133413116820938033
Consumer 2 iteration #     17 number  4133413116820938033 is not prime
Producer 0 iteration #    125 value   9033272636185151950
Consumer 2 iteration #     18 number  9033272636185151950 is not prime
Producer 0 iteration #    126 value   3351192031818134092
Consumer 2 iteration #     19 number  3351192031818134092 is not prime
Producer 0 iteration #    127 value   2364879629859318952
Consumer 2 iteration #     20 number  2364879629859318952 is not prime
Producer 0 iteration #    128 value   6999226871001937942
Consumer 2 iteration #     21 number  6999226871001937942 is not prime
Producer 0 iteration #    129 value   2858190643126429132
Consumer 2 iteration #     22 number  2858190643126429132 is not prime
Producer 0 iteration #    130 value    896329665785238790
Consumer 2 iteration #     23 number   896329665785238790 is not prime
Producer 0 iteration #    131 value    884248301457063310
Consumer 2 iteration #     24 number   884248301457063310 is not prime
Producer 0 iteration #    132 value  13579889305068052577
Consumer 2 iteration #     25 number 13579889305068052577 is not prime
Producer 0 iteration #    133 value  15515496911847392174
Consumer 2 iteration #     26 number 15515496911847392174 is not prime
Producer 0 iteration #    134 value   4224354241365366226
Consumer 2 iteration #     27 number  4224354241365366226 is not prime
Producer 0 iteration #    135 value  11074482529039115939
Producer 0 iteration #    136 value   7908489167654321175
Consumer 2 iteration #     28 number 11074482529039115939 is not prime
Consumer 2 iteration #     29 number  7908489167654321175 is not prime
Producer 0 iteration #    137 value   7022072115507729705
Consumer 2 iteration #     30 number  7022072115507729705 is not prime
Producer 0 iteration #    138 value  13084037623215382763
Consumer 2 iteration #     31 number 13084037623215382763 is not prime
Producer 0 iteration #    139 value   3528033335692006301
Consumer 2 iteration #     32 number  3528033335692006301 is not prime
Producer 0 iteration #    140 value   7376600310976927293
Consumer 2 iteration #     33 number  7376600310976927293 is not prime
Producer 0 iteration #    141 value   9886021055338442443
Consumer 2 iteration #     34 number  9886021055338442443 is not prime
Producer 0 iteration #    142 value   1130669869747947497
Consumer 2 iteration #     35 number  1130669869747947497 is not prime
Producer 0 iteration #    143 value  16535077122600244848
Consumer 2 iteration #     36 number 16535077122600244848 is not prime
Producer 0 iteration #    144 value  11867962876475057436
Consumer 2 iteration #     37 number 11867962876475057436 is not prime
Producer 0 iteration #    145 value  14301863681179894374
Consumer 2 iteration #     38 number 14301863681179894374 is not prime
Producer 0 iteration #    146 value   4129352426643240664
Consumer 2 iteration #     39 number  4129352426643240664 is not prime
Producer 0 iteration #    147 value  18182156012400057239
Consumer 2 iteration #     40 number 18182156012400057239 is not prime
Producer 0 iteration #    148 value   4641145730354838706
Consumer 2 iteration #     41 number  4641145730354838706 is not prime
Producer 0 iteration #    149 value    418941973668222617
Consumer 2 iteration #     42 number   418941973668222617 is not prime
Producer 0 iteration #    150 value  10860348332841599032
Consumer 2 iteration #     43 number 10860348332841599032 is not prime
Producer 0 iteration #    151 value  18261687408532790809
Consumer 2 iteration #     44 number 18261687408532790809 is not prime
Producer 0 iteration #    152 value  12877535677558184530
Consumer 2 iteration #     45 number 12877535677558184530 is not prime
Producer 0 iteration #    153 value  14770295510034148574
Consumer 2 iteration #     46 number 14770295510034148574 is not prime
Producer 0 iteration #    154 value   9885013543275255753
Consumer 2 iteration #     47 number  9885013543275255753 is not prime
Producer 0 iteration #    155 value     61092692573711228
Consumer 2 iteration #     48 number    61092692573711228 is not prime
Producer 0 iteration #    156 value   2042925146660822366
Consumer 2 iteration #     49 number  2042925146660822366 is not prime
Producer 0 iteration #    157 value    401841057172828188
Consumer 2 iteration #     50 number   401841057172828188 is not prime
Producer 0 iteration #    158 value   7595042349903877088
Consumer 2 iteration #     51 number  7595042349903877088 is not prime
Producer 0 iteration #    159 value  16879668850683747094
Consumer 2 iteration #     52 number 16879668850683747094 is not prime
Producer 0 iteration #    160 value   6010652712405018402
Consumer 2 iteration #     53 number  6010652712405018402 is not prime
Producer 0 iteration #    161 value   6657308194373808595
Consumer 2 iteration #     54 number  6657308194373808595 is not prime
Producer 0 iteration #    162 value  12969850969388820536
Consumer 2 iteration #     55 number 12969850969388820536 is not prime
Producer 0 iteration #    163 value  17121559935847529367
Consumer 2 iteration #     56 number 17121559935847529367 is not prime
Producer 0 iteration #    164 value   8922541255213270931
Producer 0 iteration #    165 value  13116246881251302243
Consumer 2 iteration #     57 number  8922541255213270931 is not prime
Consumer 2 iteration #     58 number 13116246881251302243 is not prime
Producer 0 iteration #    166 value  11326748604571681422
Consumer 2 iteration #     59 number 11326748604571681422 is not prime
Producer 0 iteration #    167 value   6633716714228570733
Consumer 2 iteration #     60 number  6633716714228570733 is not prime
Producer 0 iteration #    168 value  17253188459134636398
Consumer 2 iteration #     61 number 17253188459134636398 is not prime
Producer 0 iteration #    169 value   6499442702546071973
Producer 0 iteration #    170 value  13923605646254908464
Consumer 2 iteration #     62 number  6499442702546071973 is not prime
Consumer 2 iteration #     63 number 13923605646254908464 is not prime
Producer 0 iteration #    171 value    412432305928107186
Consumer 2 iteration #     64 number   412432305928107186 is not prime
Producer 0 iteration #    172 value  15040446586655852559
Consumer 2 iteration #     65 number 15040446586655852559 is not prime
Producer 0 iteration #    173 value   2611456640585750141
Producer 0 iteration #    174 value   3619911644795671144
Consumer 1 iteration #     97 number 14008227981924044893 is prime
Consumer 1 iteration #     98 number  3619911644795671144 is not prime
Consumer 1 iteration #     99 number 14952709881168912505 is not prime
Producer 0 iteration #    175 value  14952709881168912505
Producer 0 iteration #    176 value   5684109034435359482
Consumer 1 iteration #    100 number  5684109034435359482 is not prime
Producer 0 iteration #    177 value   7934681264252855260
Consumer 1 iteration #    101 number  7934681264252855260 is not prime
Producer 0 iteration #    178 value   3300084228513665523
Consumer 1 iteration #    102 number  3300084228513665523 is not prime
Producer 0 iteration #    179 value  14734347297947047374
Consumer 1 iteration #    103 number 14734347297947047374 is not prime
Producer 0 iteration #    180 value  12566423745420006957
Consumer 1 iteration #    104 number 12566423745420006957 is not prime
Producer 0 iteration #    181 value   3382901544823935819
Consumer 1 iteration #    105 number  3382901544823935819 is not prime
Producer 0 iteration #    182 value  11710961322248933997
Consumer 1 iteration #    106 number 11710961322248933997 is not prime
Producer 0 iteration #    183 value  14583070165875973719
Consumer 1 iteration #    107 number 14583070165875973719 is not prime
Producer 0 iteration #    184 value   7121316323052368754
Consumer 1 iteration #    108 number  7121316323052368754 is not prime
Producer 0 iteration #    185 value   7144640048119086695
Consumer 1 iteration #    109 number  7144640048119086695 is not prime
Producer 0 iteration #    186 value  15559042110878245430
Consumer 1 iteration #    110 number 15559042110878245430 is not prime
Producer 0 iteration #    187 value   9951692487012466524
Consumer 1 iteration #    111 number  9951692487012466524 is not prime
Producer 0 iteration #    188 value   5624332432033256176
Consumer 1 iteration #    112 number  5624332432033256176 is not prime
Producer 0 iteration #    189 value   3140904131030440259
Consumer 1 iteration #    113 number  3140904131030440259 is not prime
Producer 0 iteration #    190 value  15238331271311579290
Consumer 1 iteration #    114 number 15238331271311579290 is not prime
Producer 0 iteration #    191 value   1667586823813154771
Consumer 1 iteration #    115 number  1667586823813154771 is not prime
Producer 0 iteration #    192 value   9549139311322434735
Consumer 1 iteration #    116 number  9549139311322434735 is not prime
Producer 0 iteration #    193 value   6786318364341092210
Consumer 1 iteration #    117 number  6786318364341092210 is not prime
Producer 0 iteration #    194 value   9770890183150580872
Consumer 1 iteration #    118 number  9770890183150580872 is not prime
Producer 0 iteration #    195 value   8163359605669008420
Consumer 1 iteration #    119 number  8163359605669008420 is not prime
Producer 0 iteration #    196 value  11964304118924728151
Consumer 1 iteration #    120 number 11964304118924728151 is not prime
Producer 0 iteration #    197 value  14715090263093311424
Consumer 1 iteration #    121 number 14715090263093311424 is not prime
Producer 0 iteration #    198 value  14253644546756188756
Consumer 1 iteration #    122 number 14253644546756188756 is not prime
Producer 0 iteration #    199 value    329166851101166895
Consumer 1 iteration #    123 number   329166851101166895 is not prime
Producer 0 iteration #    200 value  11945253712518772211
Producer 0 iteration #    201 value   4063088864464666308
Consumer 1 iteration #    124 number 11945253712518772211 is not prime
Consumer 1 iteration #    125 number  4063088864464666308 is not prime
Producer 0 iteration #    202 value  10344853725340219210
Consumer 1 iteration #    126 number 10344853725340219210 is not prime
Producer 0 iteration #    203 value   1715754498183105324
Consumer 1 iteration #    127 number  1715754498183105324 is not prime
Producer 0 iteration #    204 value     12422738477716680
Consumer 1 iteration #    128 number    12422738477716680 is not prime
Producer 0 iteration #    205 value  10206343386494348936
Consumer 1 iteration #    129 number 10206343386494348936 is not prime
Producer 0 iteration #    206 value   8826842712620263393
Producer 0 iteration #    207 value   6171772183272212855
```
