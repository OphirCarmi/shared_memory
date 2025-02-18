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
Producer 0 iteration #      0 value 12483098945771958780
Consumer 3 has received a shared memory...
Consumer 3 has attached the shared memory to it's virtual memory space...
Consumer 3 iteration #      0 number 12483098945771958780 is not prime
Producer 0 iteration #      1 value 12710897413260211136
Consumer 3 iteration #      1 number 12710897413260211136 is not prime
Producer 0 iteration #      2 value  5829403774912911696
Consumer 3 iteration #      2 number  5829403774912911696 is not prime
Producer 0 iteration #      3 value  1647443027130575860
Consumer 3 iteration #      3 number  1647443027130575860 is not prime
Producer 0 iteration #      4 value  5827266137261114290
Consumer 3 iteration #      4 number  5827266137261114290 is not prime
Producer 0 iteration #      5 value   624816152517326719
Producer 0 iteration #      6 value 17415059939249560773
Consumer 3 iteration #      5 number   624816152517326719 is not prime
Consumer 3 iteration #      6 number 17415059939249560773 is not prime
Producer 0 iteration #      7 value   457148863929876244
Consumer 3 iteration #      7 number   457148863929876244 is not prime
Producer 0 iteration #      8 value  1101053443132976116
Consumer 3 iteration #      8 number  1101053443132976116 is not prime
Producer 0 iteration #      9 value  2933085584538035320
Consumer 3 iteration #      9 number  2933085584538035320 is not prime
Producer 0 iteration #     10 value  6605527672315130347
Producer 0 iteration #     11 value 16513648483780287522
Consumer 3 iteration #     10 number  6605527672315130347 is not prime
Consumer 3 iteration #     11 number 16513648483780287522 is not prime
Producer 0 iteration #     12 value 12448788521433572276
Consumer 3 iteration #     12 number 12448788521433572276 is not prime
Producer 0 iteration #     13 value 12169201208118710340
Consumer 3 iteration #     13 number 12169201208118710340 is not prime
Producer 0 iteration #     14 value  4216694758549227388
Consumer 3 iteration #     14 number  4216694758549227388 is not prime
Producer 0 iteration #     15 value 17480439852218118034
Consumer 3 iteration #     15 number 17480439852218118034 is not prime
Producer 0 iteration #     16 value 10335250223023142946
Consumer 3 iteration #     16 number 10335250223023142946 is not prime
Producer 0 iteration #     17 value  3185824158639097054
Consumer 3 iteration #     17 number  3185824158639097054 is not prime
Producer 0 iteration #     18 value  7044626879665724320
Consumer 3 iteration #     18 number  7044626879665724320 is not prime
Producer 0 iteration #     19 value 17589650747984907783
Consumer 3 iteration #     19 number 17589650747984907783 is not prime
Producer 0 iteration #     20 value 14883555612015041167
Consumer 3 iteration #     20 number 14883555612015041167 is not prime
Producer 0 iteration #     21 value 11298299094880651144
Consumer 3 iteration #     21 number 11298299094880651144 is not prime
Producer 0 iteration #     22 value  3406816662853205156
Consumer 3 iteration #     22 number  3406816662853205156 is not prime
Producer 0 iteration #     23 value  2470666164291964818
Consumer 3 iteration #     23 number  2470666164291964818 is not prime
Producer 0 iteration #     24 value 15956030215252984521
Consumer 3 iteration #     24 number 15956030215252984521 is not prime
Producer 0 iteration #     25 value 16410250555874370035
Consumer 3 iteration #     25 number 16410250555874370035 is not prime
Producer 0 iteration #     26 value  1744078778659696894
Consumer 3 iteration #     26 number  1744078778659696894 is not prime
Producer 0 iteration #     27 value  1289709190420554242
Consumer 3 iteration #     27 number  1289709190420554242 is not prime
Producer 0 iteration #     28 value 11665879236510702164
Consumer 3 iteration #     28 number 11665879236510702164 is not prime
Producer 0 iteration #     29 value  6878070520539974776
Consumer 3 iteration #     29 number  6878070520539974776 is not prime
Producer 0 iteration #     30 value 14158244738681098817
Consumer 3 iteration #     30 number 14158244738681098817 is not prime
Producer 0 iteration #     31 value 13585022411815606359
Consumer 3 iteration #     31 number 13585022411815606359 is not prime
Producer 0 iteration #     32 value  1771258447466527955
Consumer 3 iteration #     32 number  1771258447466527955 is not prime
Producer 0 iteration #     33 value   271483490286802022
Consumer 3 iteration #     33 number   271483490286802022 is not prime
Producer 0 iteration #     34 value 11827588237048392178
Consumer 3 iteration #     34 number 11827588237048392178 is not prime
Producer 0 iteration #     35 value  6187623099851920349
Consumer 3 iteration #     35 number  6187623099851920349 is not prime
Producer 0 iteration #     36 value 13941116078582168723
Consumer 3 iteration #     36 number 13941116078582168723 is not prime
Producer 0 iteration #     37 value 15193395078677210625
Consumer 3 iteration #     37 number 15193395078677210625 is not prime
Producer 0 iteration #     38 value  4224521495082691540
Consumer 3 iteration #     38 number  4224521495082691540 is not prime
Producer 0 iteration #     39 value 13156260899715678565
Consumer 3 iteration #     39 number 13156260899715678565 is not prime
Producer 0 iteration #     40 value 12077090190858912543
Consumer 3 iteration #     40 number 12077090190858912543 is not prime
Producer 0 iteration #     41 value  6380977095234970064
Consumer 3 iteration #     41 number  6380977095234970064 is not prime
Producer 0 iteration #     42 value  3618640181314558465
Consumer 3 iteration #     42 number  3618640181314558465 is not prime
Producer 0 iteration #     43 value  9246960080720963622
Consumer 3 iteration #     43 number  9246960080720963622 is not prime
Producer 0 iteration #     44 value  2049810945846172170
Consumer 3 iteration #     44 number  2049810945846172170 is not prime
Producer 0 iteration #     45 value  4569075089811475504
Consumer 3 iteration #     45 number  4569075089811475504 is not prime
Producer 0 iteration #     46 value 10489471670060865906
Consumer 3 iteration #     46 number 10489471670060865906 is not prime
Producer 0 iteration #     47 value 10162650717940263013
Consumer 3 iteration #     47 number 10162650717940263013 is not prime
Producer 0 iteration #     48 value 17698913674324112753
Consumer 3 iteration #     48 number 17698913674324112753 is not prime
Producer 0 iteration #     49 value  2792842640677861110
Consumer 3 iteration #     49 number  2792842640677861110 is not prime
Producer 0 iteration #     50 value 16140704864443570138
Consumer 3 iteration #     50 number 16140704864443570138 is not prime
Producer 0 iteration #     51 value 12440103197970361713
Consumer 3 iteration #     51 number 12440103197970361713 is not prime
Producer 0 iteration #     52 value  8737685213826925533
Consumer 3 iteration #     52 number  8737685213826925533 is not prime
Producer 0 iteration #     53 value 13038437010845346430
Consumer 3 iteration #     53 number 13038437010845346430 is not prime
Producer 0 iteration #     54 value 17419878516015170377
Consumer 3 iteration #     54 number 17419878516015170377 is not prime
Producer 0 iteration #     55 value  6849444754975099966
Consumer 3 iteration #     55 number  6849444754975099966 is not prime
Producer 0 iteration #     56 value  1890726550841638743
Consumer 3 iteration #     56 number  1890726550841638743 is not prime
Producer 0 iteration #     57 value 10316372923357469395
Consumer 3 iteration #     57 number 10316372923357469395 is not prime
Producer 0 iteration #     58 value  4133960856942573707
Consumer 3 iteration #     58 number  4133960856942573707 is not prime
Producer 0 iteration #     59 value  8583184083457601014
Consumer 3 iteration #     59 number  8583184083457601014 is not prime
Producer 0 iteration #     60 value  5759012058290216499
Consumer 3 iteration #     60 number  5759012058290216499 is not prime
Producer 0 iteration #     61 value 15051179383557254830
Consumer 3 iteration #     61 number 15051179383557254830 is not prime
Producer 0 iteration #     62 value 10015170123886663010
Consumer 3 iteration #     62 number 10015170123886663010 is not prime
Producer 0 iteration #     63 value 11185412853308755319
Consumer 3 iteration #     63 number 11185412853308755319 is not prime
Producer 0 iteration #     64 value 15580333649313876250
Consumer 3 iteration #     64 number 15580333649313876250 is not prime
Producer 0 iteration #     65 value 18201632878778701571
Producer 0 iteration #     66 value 12378147108616035889
Consumer 3 iteration #     65 number 18201632878778701571 is not prime
Consumer 3 iteration #     66 number 12378147108616035889 is not prime
Producer 0 iteration #     67 value  1325651068358696304
Consumer 3 iteration #     67 number  1325651068358696304 is not prime
Producer 0 iteration #     68 value 15665809666502954245
Consumer 3 iteration #     68 number 15665809666502954245 is not prime
Producer 0 iteration #     69 value  7945140707486044418
Consumer 3 iteration #     69 number  7945140707486044418 is not prime
Producer 0 iteration #     70 value  8533099963044748089
Consumer 3 iteration #     70 number  8533099963044748089 is not prime
Producer 0 iteration #     71 value  2469126265274849646
Consumer 3 iteration #     71 number  2469126265274849646 is not prime
Producer 0 iteration #     72 value 10637118513425789414
Consumer 3 iteration #     72 number 10637118513425789414 is not prime
Producer 0 iteration #     73 value  2517763525894998096
Consumer 3 iteration #     73 number  2517763525894998096 is not prime
Producer 0 iteration #     74 value 14648178409612242823
Consumer 3 iteration #     74 number 14648178409612242823 is not prime
Producer 0 iteration #     75 value  1566331210261407887
Consumer 3 iteration #     75 number  1566331210261407887 is not prime
Producer 0 iteration #     76 value  2054793600007203741
Consumer 3 iteration #     76 number  2054793600007203741 is not prime
Producer 0 iteration #     77 value 16479726806567109814
Consumer 3 iteration #     77 number 16479726806567109814 is not prime
Producer 0 iteration #     78 value 15286635035843697802
Consumer 3 iteration #     78 number 15286635035843697802 is not prime
Producer 0 iteration #     79 value  7100838266969135209
Producer 0 iteration #     80 value  8547580536069660675
Consumer 1 has received a shared memory...
Consumer 1 has attached the shared memory to it's virtual memory space...
Consumer 1 iteration #      0 number  8547580536069660675 is not prime
Producer 0 iteration #     81 value 10361077315561607103
Producer 0 iteration #     82 value 10163480639323124056
Consumer 2 has received a shared memory...
Consumer 2 has attached the shared memory to it's virtual memory space...
Consumer 2 iteration #      0 number 10361077315561607103 is not prime
Consumer 1 iteration #      1 number 10163480639323124056 is not prime
Producer 0 iteration #     83 value 17561682080920592448
Consumer 2 iteration #      1 number 17561682080920592448 is not prime
Producer 0 iteration #     84 value 17454105984211601522
Consumer 2 iteration #      2 number 17454105984211601522 is not prime
Producer 0 iteration #     85 value  7466771630980730388
Consumer 1 iteration #      2 number  7466771630980730388 is not prime
Consumer 1 iteration #      3 number 11104685384749039303 is not prime
Producer 0 iteration #     86 value 11104685384749039303
Producer 0 iteration #     87 value 14657202139811493131
Consumer 2 iteration #      3 number 14657202139811493131 is not prime
Producer 0 iteration #     88 value  8151730893454213518
Consumer 1 iteration #      4 number  8151730893454213518 is not prime
Consumer 1 iteration #      5 number 10130903864383513044 is not prime
Producer 0 iteration #     89 value 10130903864383513044
Producer 0 iteration #     90 value 18134135913065467572
Consumer 2 iteration #      4 number 18134135913065467572 is not prime
Consumer 1 iteration #      6 number 11861277968331290224 is not prime
Producer 0 iteration #     91 value 11861277968331290224
Producer 0 iteration #     92 value  3576317594210658934
Consumer 2 iteration #      5 number  3576317594210658934 is not prime
Consumer 2 iteration #      6 number 18218632806859416206 is not prime
Producer 0 iteration #     93 value 18218632806859416206
Producer 0 iteration #     94 value 17662887680649084612
Consumer 1 iteration #      7 number 17662887680649084612 is not prime
Producer 0 iteration #     95 value 10331768596881643226
Consumer 2 iteration #      7 number 10331768596881643226 is not prime
Producer 0 iteration #     96 value  8334356364183300349
Producer 0 iteration #     97 value  1649223910890732353
Consumer 1 iteration #      8 number  1649223910890732353 is not prime
Producer 0 iteration #     98 value 13802162520450920196
Consumer 1 iteration #      9 number 13802162520450920196 is not prime
Consumer 2 iteration #      8 number  8334356364183300349 is not prime
Producer 0 iteration #     99 value  8570258543668157432
Consumer 1 iteration #     10 number  8570258543668157432 is not prime
Consumer 1 iteration #     11 number 16035879841081534599 is not prime
Producer 0 iteration #    100 value 16035879841081534599
Producer 0 iteration #    101 value 14237508763117035881
Consumer 2 iteration #      9 number 14237508763117035881 is not prime
Producer 0 iteration #    102 value  1354818976457288328
Consumer 1 iteration #     12 number  1354818976457288328 is not prime
Consumer 1 iteration #     13 number 13432928011500187450 is not prime
Producer 0 iteration #    103 value 13432928011500187450
Producer 0 iteration #    104 value 13690004111310522516
Consumer 1 iteration #     14 number 13690004111310522516 is not prime
Producer 0 iteration #    105 value  2570677754260365383
Consumer 1 iteration #     15 number  2570677754260365383 is not prime
Producer 0 iteration #    106 value 17825527212979883018
Consumer 2 iteration #     10 number 17825527212979883018 is not prime
Producer 0 iteration #    107 value  8517785459834826893
Producer 0 iteration #    108 value  6069283090057613918
Consumer 1 iteration #     16 number  6069283090057613918 is not prime
Producer 0 iteration #    109 value  6630968919944014351
Producer 0 iteration #    110 value  9672246569403110472
Consumer 1 iteration #     17 number  6630968919944014351 is not prime
Consumer 1 iteration #     18 number  9672246569403110472 is not prime
Producer 0 iteration #    111 value  5216510749658203435
Consumer 1 iteration #     19 number  5216510749658203435 is not prime
Producer 0 iteration #    112 value  5590415727574938807
Consumer 1 iteration #     20 number  5590415727574938807 is not prime
Producer 0 iteration #    113 value 16610072766352677615
Consumer 1 iteration #     21 number 16610072766352677615 is not prime
Producer 0 iteration #    114 value 16193740638102925722
Consumer 1 iteration #     22 number 16193740638102925722 is not prime
Producer 0 iteration #    115 value 11523846160291358373
Consumer 1 iteration #     23 number 11523846160291358373 is not prime
Producer 0 iteration #    116 value  5042221245043297136
Consumer 1 iteration #     24 number  5042221245043297136 is not prime
Producer 0 iteration #    117 value  9831043939791721613
Consumer 1 iteration #     25 number  9831043939791721613 is not prime
Producer 0 iteration #    118 value 13149258044171299743
Consumer 1 iteration #     26 number 13149258044171299743 is not prime
Producer 0 iteration #    119 value  4744718642611769891
Consumer 1 iteration #     27 number  4744718642611769891 is not prime
Producer 0 iteration #    120 value 10074074931085934061
Consumer 1 iteration #     28 number 10074074931085934061 is not prime
Producer 0 iteration #    121 value  1590388375141231573
Producer 0 iteration #    122 value  7861529426486885066
Consumer 1 iteration #     29 number  1590388375141231573 is not prime
Consumer 1 iteration #     30 number  7861529426486885066 is not prime
Producer 0 iteration #    123 value  3317354825633468469
Consumer 1 iteration #     31 number  3317354825633468469 is not prime
Producer 0 iteration #    124 value  9198492841118535036
Consumer 1 iteration #     32 number  9198492841118535036 is not prime
Producer 0 iteration #    125 value 15337036641223558763
Producer 0 iteration #    126 value  2201192575741706831
Consumer 3 iteration #     79 number  7100838266969135209 is not prime
Consumer 3 iteration #     80 number  2201192575741706831 is not prime
Producer 0 iteration #    127 value  7187743584792033449
Producer 0 iteration #    128 value 18201717130553129468
Consumer 1 iteration #     33 number 15337036641223558763 is prime
Consumer 1 iteration #     34 number 18201717130553129468 is not prime
Consumer 1 iteration #     35 number 12191643815627558877 is not prime
Producer 0 iteration #    129 value 12191643815627558877
Producer 0 iteration #    130 value 11803526209038144063
Consumer 1 iteration #     36 number 11803526209038144063 is not prime
Producer 0 iteration #    131 value  3539140005590620821
Consumer 1 iteration #     37 number  3539140005590620821 is not prime
Producer 0 iteration #    132 value    72943652254652170
Consumer 1 iteration #     38 number    72943652254652170 is not prime
Producer 0 iteration #    133 value 10226436096791246515
Consumer 1 iteration #     39 number 10226436096791246515 is not prime
Producer 0 iteration #    134 value  4586393541371949599
Consumer 1 iteration #     40 number  4586393541371949599 is not prime
Producer 0 iteration #    135 value 15097814264592799791
Consumer 1 iteration #     41 number 15097814264592799791 is not prime
Producer 0 iteration #    136 value  3606461591132587883
Consumer 1 iteration #     42 number  3606461591132587883 is not prime
Producer 0 iteration #    137 value  2981739966615670913
Producer 0 iteration #    138 value  3641286825167060829
Consumer 3 iteration #     81 number  7187743584792033449 is prime
Consumer 3 iteration #     82 number  3641286825167060829 is not prime
Consumer 3 iteration #     83 number 13946169401946883616 is not prime
Producer 0 iteration #    139 value 13946169401946883616
Producer 0 iteration #    140 value  9723112030603238125
Producer 0 iteration #    141 value 11983761242269919584
Consumer 3 iteration #     84 number  9723112030603238125 is not prime
Consumer 3 iteration #     85 number 11983761242269919584 is not prime
Producer 0 iteration #    142 value  6167885348769104792
Consumer 3 iteration #     86 number  6167885348769104792 is not prime
Producer 0 iteration #    143 value 15725631476150730952
Consumer 3 iteration #     87 number 15725631476150730952 is not prime
Producer 0 iteration #    144 value 15647741153100132198
Consumer 3 iteration #     88 number 15647741153100132198 is not prime
Producer 0 iteration #    145 value 16759778220361949758
Consumer 3 iteration #     89 number 16759778220361949758 is not prime
Producer 0 iteration #    146 value 14249354860210828325
Consumer 3 iteration #     90 number 14249354860210828325 is not prime
Producer 0 iteration #    147 value 12560211705091767871
Consumer 3 iteration #     91 number 12560211705091767871 is not prime
Producer 0 iteration #    148 value  3571027912980359509
Consumer 3 iteration #     92 number  3571027912980359509 is not prime
Producer 0 iteration #    149 value  5272364757100087190
Consumer 3 iteration #     93 number  5272364757100087190 is not prime
Producer 0 iteration #    150 value  4904530729579853346
Consumer 3 iteration #     94 number  4904530729579853346 is not prime
Producer 0 iteration #    151 value  6739961437455899846
Consumer 3 iteration #     95 number  6739961437455899846 is not prime
Producer 0 iteration #    152 value 13343789116061239184
Consumer 3 iteration #     96 number 13343789116061239184 is not prime
Producer 0 iteration #    153 value   589106086844267211
Consumer 3 iteration #     97 number   589106086844267211 is not prime
Producer 0 iteration #    154 value  5280212290595808719
Consumer 3 iteration #     98 number  5280212290595808719 is not prime
Producer 0 iteration #    155 value 11312206872019766933
Consumer 3 iteration #     99 number 11312206872019766933 is not prime
Producer 0 iteration #    156 value 12767699738706161769
Consumer 3 iteration #    100 number 12767699738706161769 is not prime
Producer 0 iteration #    157 value 12996191409308171728
Consumer 3 iteration #    101 number 12996191409308171728 is not prime
Producer 0 iteration #    158 value  1605184533277122339
Consumer 3 iteration #    102 number  1605184533277122339 is not prime
Producer 0 iteration #    159 value 10328787261351672637
Consumer 3 iteration #    103 number 10328787261351672637 is not prime
Producer 0 iteration #    160 value  6882833051274320332
Consumer 3 iteration #    104 number  6882833051274320332 is not prime
Producer 0 iteration #    161 value 11201530869114947876
Consumer 3 iteration #    105 number 11201530869114947876 is not prime
Producer 0 iteration #    162 value  2439866822252953569
Consumer 3 iteration #    106 number  2439866822252953569 is not prime
Producer 0 iteration #    163 value 11658116522261139881
Producer 0 iteration #    164 value 13944107883259837190
Consumer 3 iteration #    107 number 11658116522261139881 is not prime
Consumer 3 iteration #    108 number 13944107883259837190 is not prime
Producer 0 iteration #    165 value  1963322098851625119
Consumer 3 iteration #    109 number  1963322098851625119 is not prime
Producer 0 iteration #    166 value 16999655324099388000
Consumer 3 iteration #    110 number 16999655324099388000 is not prime
Producer 0 iteration #    167 value 17986457348755819857
Consumer 3 iteration #    111 number 17986457348755819857 is not prime
Producer 0 iteration #    168 value 17322854372825875266
Consumer 3 iteration #    112 number 17322854372825875266 is not prime
Producer 0 iteration #    169 value 15627124081650026121
Consumer 3 iteration #    113 number 15627124081650026121 is not prime
Producer 0 iteration #    170 value  1132132128036335114
Consumer 3 iteration #    114 number  1132132128036335114 is not prime
Producer 0 iteration #    171 value  7757251392168403408
Consumer 3 iteration #    115 number  7757251392168403408 is not prime
Producer 0 iteration #    172 value  1641660951869750372
Consumer 3 iteration #    116 number  1641660951869750372 is not prime
Producer 0 iteration #    173 value 14731606593517906010
Consumer 3 iteration #    117 number 14731606593517906010 is not prime
Producer 0 iteration #    174 value 13441556167385616982
Consumer 3 iteration #    118 number 13441556167385616982 is not prime
Producer 0 iteration #    175 value  7720223650942931267
Producer 0 iteration #    176 value  6058411680312927533
Consumer 1 iteration #     43 number  2981739966615670913 is prime
Consumer 1 iteration #     44 number  6058411680312927533 is not prime
Consumer 1 iteration #     45 number  5804421647884009337 is not prime
Producer 0 iteration #    177 value  5804421647884009337
Producer 0 iteration #    178 value 18157899404696002328
Producer 0 iteration #    179 value  8255436048295352462
Consumer 1 iteration #     46 number 18157899404696002328 is not prime
Consumer 1 iteration #     47 number  8255436048295352462 is not prime
Producer 0 iteration #    180 value  2122552232241730270
Consumer 1 iteration #     48 number  2122552232241730270 is not prime
Producer 0 iteration #    181 value  5544310286294880254
Consumer 1 iteration #     49 number  5544310286294880254 is not prime
Producer 0 iteration #    182 value 14826027858522880684
Consumer 1 iteration #     50 number 14826027858522880684 is not prime
Producer 0 iteration #    183 value   138838352685499980
Consumer 1 iteration #     51 number   138838352685499980 is not prime
Producer 0 iteration #    184 value 10695147300879349268
Consumer 1 iteration #     52 number 10695147300879349268 is not prime
Producer 0 iteration #    185 value  2572239834265552447
Consumer 1 iteration #     53 number  2572239834265552447 is not prime
Producer 0 iteration #    186 value 13811066741525032781
Consumer 1 iteration #     54 number 13811066741525032781 is not prime
Producer 0 iteration #    187 value  1619349402583255470
Consumer 1 iteration #     55 number  1619349402583255470 is not prime
Producer 0 iteration #    188 value  7989756229916137451
Consumer 1 iteration #     56 number  7989756229916137451 is not prime
Producer 0 iteration #    189 value 13577850264317641124
Consumer 1 iteration #     57 number 13577850264317641124 is not prime
Producer 0 iteration #    190 value 10212542316966821322
Consumer 1 iteration #     58 number 10212542316966821322 is not prime
Producer 0 iteration #    191 value  7228065937850267811
Consumer 1 iteration #     59 number  7228065937850267811 is not prime
Producer 0 iteration #    192 value 14792256352068450077
Producer 0 iteration #    193 value  6450791137625353510
Consumer 2 iteration #     11 number  8517785459834826893 is prime
Consumer 2 iteration #     12 number  6450791137625353510 is not prime
Producer 0 iteration #    194 value  5306270001403453937
Consumer 2 iteration #     13 number  5306270001403453937 is not prime
Producer 0 iteration #    195 value 16405005450882992152
Consumer 2 iteration #     14 number 16405005450882992152 is not prime
Producer 0 iteration #    196 value 12637957104530125514
Consumer 2 iteration #     15 number 12637957104530125514 is not prime
Producer 0 iteration #    197 value  7532614976654415030
Consumer 2 iteration #     16 number  7532614976654415030 is not prime
Producer 0 iteration #    198 value   381177133723736507
Producer 0 iteration #    199 value 15018611052236173162
Consumer 2 iteration #     17 number   381177133723736507 is not prime
Consumer 2 iteration #     18 number 15018611052236173162 is not prime
Producer 0 iteration #    200 value 17768878868377256728
Consumer 2 iteration #     19 number 17768878868377256728 is not prime
Producer 0 iteration #    201 value 12352261511545973608
Consumer 2 iteration #     20 number 12352261511545973608 is not prime
Producer 0 iteration #    202 value 13055685809579102842
Consumer 2 iteration #     21 number 13055685809579102842 is not prime
Producer 0 iteration #    203 value  8496611736039653615
Consumer 2 iteration #     22 number  8496611736039653615 is not prime
Producer 0 iteration #    204 value   524890391470908745
Consumer 2 iteration #     23 number   524890391470908745 is not prime
Producer 0 iteration #    205 value    76585438746200637
Consumer 2 iteration #     24 number    76585438746200637 is not prime
Producer 0 iteration #    206 value   590246629826543944
Consumer 2 iteration #     25 number   590246629826543944 is not prime
Producer 0 iteration #    207 value  7776616127453523534
Consumer 2 iteration #     26 number  7776616127453523534 is not prime
Producer 0 iteration #    208 value  7008135829690977873
Consumer 2 iteration #     27 number  7008135829690977873 is not prime
Producer 0 iteration #    209 value  3685940689492149051
Consumer 2 iteration #     28 number  3685940689492149051 is not prime
Producer 0 iteration #    210 value  4502374707910170307
Producer 0 iteration #    211 value  8583622886301352017
Consumer 2 iteration #     29 number  4502374707910170307 is not prime
Consumer 2 iteration #     30 number  8583622886301352017 is not prime
Consumer 2 iteration #     31 number  9987865013873071915 is not prime
Producer 0 iteration #    212 value  9987865013873071915
Producer 0 iteration #    213 value 15196284156543618769
Producer 0 iteration #    214 value   261950463548856328
Consumer 2 iteration #     32 number 15196284156543618769 is not prime
Consumer 2 iteration #     33 number   261950463548856328 is not prime
Producer 0 iteration #    215 value 13441051258990086858
Consumer 2 iteration #     34 number 13441051258990086858 is not prime
Producer 0 iteration #    216 value 16864967541261234960
Consumer 2 iteration #     35 number 16864967541261234960 is not prime
Producer 0 iteration #    217 value  7928840070635150927
Consumer 2 iteration #     36 number  7928840070635150927 is not prime
Producer 0 iteration #    218 value  9271710298462174965
Consumer 2 iteration #     37 number  9271710298462174965 is not prime
Producer 0 iteration #    219 value 15078709484611201050
Consumer 2 iteration #     38 number 15078709484611201050 is not prime
Producer 0 iteration #    220 value  6358648064157913764
Consumer 2 iteration #     39 number  6358648064157913764 is not prime
Producer 0 iteration #    221 value 11988395883531072940
Consumer 2 iteration #     40 number 11988395883531072940 is not prime
Producer 0 iteration #    222 value 18123369123323036728
Consumer 2 iteration #     41 number 18123369123323036728 is not prime
Producer 0 iteration #    223 value 11009959644197544186
Consumer 2 iteration #     42 number 11009959644197544186 is not prime
Producer 0 iteration #    224 value  1919213637386070200
Consumer 2 iteration #     43 number  1919213637386070200 is not prime
Producer 0 iteration #    225 value  6514016140214557050
Consumer 2 iteration #     44 number  6514016140214557050 is not prime
Producer 0 iteration #    226 value 10611183627819378051
Consumer 2 iteration #     45 number 10611183627819378051 is not prime
Producer 0 iteration #    227 value   117846177868775191
Consumer 2 iteration #     46 number   117846177868775191 is not prime
Producer 0 iteration #    228 value 16882642129796777481
Consumer 2 iteration #     47 number 16882642129796777481 is not prime
Producer 0 iteration #    229 value 12880956942787279002
Consumer 2 iteration #     48 number 12880956942787279002 is not prime
Producer 0 iteration #    230 value 10401961926994490532
Consumer 2 iteration #     49 number 10401961926994490532 is not prime
Producer 0 iteration #    231 value 11179440909875264673
Consumer 2 iteration #     50 number 11179440909875264673 is not prime
Producer 0 iteration #    232 value 13408196416138641346
Consumer 2 iteration #     51 number 13408196416138641346 is not prime
Producer 0 iteration #    233 value  1544011834345015187
Consumer 2 iteration #     52 number  1544011834345015187 is not prime
Producer 0 iteration #    234 value  1461904177144402093
Producer 0 iteration #    235 value 11290137880589566891
Consumer 2 iteration #     53 number  1461904177144402093 is not prime
Producer 0 iteration #    236 value  3786904351314664427
Consumer 2 iteration #     54 number 11290137880589566891 is not prime
Producer 0 iteration #    237 value 12457012624106449290
Consumer 2 iteration #     55 number  3786904351314664427 is not prime
Consumer 2 iteration #     56 number 12457012624106449290 is not prime
Producer 0 iteration #    238 value  7489485086845734761
Producer 0 iteration #    239 value 10064827182176214171
```
