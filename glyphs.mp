defchar(allah,-1,2000,6,-1);
%%backgroundimage:images/Allah.jpg,-133.518,-1296.25,1,0,0,1
%%beginparams
z1 = (334.009,30.436);
z2 = (586.936,58.8696);
z3 = (581.855,-39.2516);
z4 = (323.122,-68.9698);

%%beginpaths

fill
(0.902777,8.51857) .. tension 1.08559 and 1.40034 ..
(76.5317,138.325) .. tension 1.18822 and 1.66043 ..
(176.682,206.795) .. tension 1.20232 and 1.73144 ..
 {right}(242.348,333.425) .. tension 2.02267 and 0.75 ..
 {down}(252.777,205.024) .. tension 1.94044 and 0.951134 ..
 {right}z1 .. tension 1 and 1 ..
(404.619,64.5121) .. tension 0.791136 and 1.20485 ..
 {up}(423.828,109.836) .. tension 2.53865 and 1.23111 ..
 {up}(387.539,382.138) .. tension 2.02879 and 1.37353 ..
 {right}(421.047,422.371) .. tension 1.36839 and 1.37187 ..
(449.498,364.588) .. tension 1.48638 and 2.23839 ..
(495.624,119.556) .. tension 2.19128 and 0.75 ..
 {right}z2 .. tension 1 and 1.63689 ..
 {up}(598.337,77.002) .. tension 3.69782 and 1 ..
(557.985,173.344) .. tension 1.45202 and 2.04686 ..
 {up}(524.256,313.766) .. tension 1 and 1.69311 ..
 {right}(558.075,422.061) .. tension 1.23227 and 1.23227 ..
 {down}(580.625,392.569) .. tension 1 and 1 ..
(604.026,267.746) .. tension 1 and 0.941589 ..
 {down}(656.663,107.786) .. tension 1.4891 and 1.23831 ..
 {left}z3 .. tension 0.75 and 1.23383 ..
(453.64,23.2539) .. tension 1 and 1.09581 ..
 {left}(448.962,25.7639) .. tension 2.5296 and 1 ..
(423.241,-5.7866) .. tension 1.17827 and 1 ..
 {left}z4 .. tension 0.827491 and 1 ..
(216.724,5.64641) .. tension 1 and 2.37499 ..
 {left}(198.258,41.331) .. tension 2.65441 and 1 ..
(173.005,23.0092) .. tension 1.45947 and 0.75 ..
 {left}(74.0316,-17.145) .. tension 1 and 2.39869 ..
 {up} cycle
;
fill
(88.5417,81.216) .. tension 3.03923 and 2.38709 ..
(187.891,95.5336) .. tension 2.14764 and 3.13157 ..
 {left}(187.173,149.059) .. tension 3.58852 and 2.52398 ..
 {down} cycle
;

%%endpaths
%%beginbody

glyphs[allah].points[1] := z1;
glyphs[allah].points[2] := z2;
glyphs[allah].points[3] := z3;
glyphs[allah].points[4] := z4;

savepicture:=1;

enddefchar;
defchar(lamalef.isol,-1,680,6,-1);
%%backgroundimage:images/lam.alef.jpg,-72.9499,-1174.04,1,0,0,1
%%beginparams
z1 = (427.442,69.2108);
z2 = (297.271,-37.2622);

%%beginpaths

fill
(306.872,58.9436) .. tension 1.73784 and 1 ..
(461.833,265.416) .. tension 0.968917 and 3.33846 ..
 {up}(501.735,511.557) .. tension 1.78394 and 1.41973 ..
 {up}(494.099,558.248) .. tension 1 and 4.04886 ..
 {right}(561.499,674.49) .. tension 1 and 1 ..
(574.77,650.478) .. tension 1 and 1 ..
(578.258,576.024) .. tension 1 and 2.70359 ..
 {down}(619.012,534.281) .. tension 0.75 and 4.86442 ..
(561.288,459.637) .. tension 6.90433 and 2.12776 ..
(557.365,431.555) .. tension 0.75 and 1.26701 ..
(475.09,151.212) .. tension 0.93248 and 5.10177 ..
 {down}z1 .. tension 3.36951 and 9.7044 ..
(465.072,75.0285) .. tension 4.86204 and 0.75 ..
(443.974,118.095) .. tension 1 and 8.15346 ..
(313.146,301.624) .. tension 1.82294 and 3.44624 ..
 {left}(176.002,432.837) .. tension 1.51642 and 1.05099 ..
 {left}(158.622,425.259) .. tension 1.57491 and 1.18186 ..
 {up}(31.5104,527.297) .. tension 1 and 1.27517 ..
 {right}(62.6082,619.434) .. tension 4.23328 and 0.830346 ..
(254.565,474.044) .. tension 0.856461 and 3.75129 ..
 {down}(531.739,70.226) .. tension 1 and 6.48608 ..
(503.129,-17.6155) .. tension 27.3804 and 11.2752 ..
 {left}z2 .. tension 0.75 and 1.13828 ..
 {up}(230.93,8.14009) .. tension 2.01909 and 1.49069 ..
 {right}(259.577,66.8397) .. tension 1.24669 and 1.17281 ..
 {right} cycle
;

%%endpaths
%%beginbody
%charwd := xpart lrcorner currentpicture -x1 + rightbearing;
%currentpicture := currentpicture shifted (-x1,0);

%labels(1,2);


enddefchar;
defchar(behbeh,-1,-1,6,-1);
%%backgroundimage:images/beh.init_beh.jpg,-928.173,-1070.45,1,0,0,1
%%beginparams
z1 = (298.406,111.819);
z2 = (287.019,10.6207);

%%beginpaths

fill
(181.694,150.606) .. tension 2.22 and 0.75 ..
 {right}z1 .. tension 1 and 1.08873 ..
 {up}(305.227,125.159) .. tension 2.7423 and 1 ..
 {up}(287.461,206.666) .. tension 1 and 1.56913 ..
 {right}(315.967,265.172) .. tension 2.19457 and 1 ..
 {down}(366.516,172.118) .. tension 1 and 1.13994 ..
 {left}z2 .. tension 0.901215 and 7.29269 ..
 {left}(172.913,54.3294) .. tension 1.08647 and 1 ..
bldmv ( (142.026,43.0063), (10.3935,5.05091), (33.8863,4.45281) ) .. tension 1 and 1 ..
bldmv ( (55.2752,4.93602), (-11.3333,9.16667), (85.8089,-3.32754) ) leftjoin
bldmv ( (71.3822,103.592), (-12,3), (100.614,8.77701) ) .. tension 1 and 1 ..
bldmv ( (141.15,133.223), (14,9), (19.4026,-0.482255) ) .. tension 1 and 1.91014 ..
 {right} cycle
;

%%endpaths
enddefchar;
beginchar(notdef,0,-1,-1,-1);
%%backgroundimage:images/nodef.png,-752.949,-1178.7,8,0,0,8

%%beginpaths

fill
(-42.2071,588.054) .. tension 1 and 1 ..
 {right}(165.312,781.92) .. tension 1 and 1 ..
 {down}(350.438,636.595) .. tension 1 and 1 ..
 {left}(279.936,518.4) .. tension 1 and 1 ..
 {up}(186.624,586.829) .. tension 0.93744 and 1.09623 ..
 {up}(256.666,697.075) .. tension 1 and 1 ..
 {left}(184.55,740.275) .. tension 1 and 1 ..
 {down}(78.7968,659.405) .. tension 1 and 1 ..
 {down}(201.898,363.101) .. tension 1 and 3.43742 ..
 {left}(168.269,223.776) .. tension 1.56096 and 1 ..
 {up}(151.046,269.088) .. tension 1 and 1 ..
 {up} cycle
;
fill
(73.6776,83.6076) .. tension 1 and 1 ..
(234.921,86.5935) .. tension 1 and 1 ..
 cycle
;

%%endpaths
%%beginbody
% glyphname:space
%%begincomponents
%%endcomponents
endchar;
beginchar(null,1,-1,-1,-1);
%%beginbody
charwd := 0;
endchar;
beginchar(linefeed,10,-1,-1,-1);
%%beginbody
charwd := 0;
endchar;
beginchar(zwj,8205,-1,-1,-1);
%%beginbody
%847
charwd := 0;
endchar;
beginchar(cgj,847,-1,-1,-1);
%%beginbody
%847
charwd := 0;
endchar;
defchar(space,32,-1,-1,-1);
%%beginbody


charwd := 100 + lefttatweel  *nuqta ;
enddefchar;
beginchar(space.ii,-1,-1,-1,-1);
%%beginbody
charwd := 0;
endchar;
beginchar(rubelhizb,1758,-1,-1,-1);
%%backgroundimage:images/hizb.jpg,-4049.19,-1130.17,1,0,0,1
%%beginparams
z1 = (834.667,495);
z2 = (409,1010);

%%beginpaths

controlledPath (0,6)(_pii)(
(683.667,611.5) {dir -21.0218} .. tension 0.943006 and 2.66474 ..
(779.778,537.606) .. tension 1 and 1.20533 ..
 {down}z1 ..
 {up} cycle
);
controlledPath (1,0)(_piii)(
(x2,886.498) .. tension 2.87631 and 3.09002 ..
 {down}(481.251,737.028) .. tension 1.84928 and 2.5898 ..
 {left}(458.096,677.376) .. tension 1.34783 and 0.75 ..
 {up}(448.901,716.146) .. tension 6.08006 and 1.52918 ..
 {left}(x2,797.1) .. tension 2.85131 ..
 {right} cycle
);
controlledPath (3,0)(_piv)(
(744.877,y1) {up} .. tension 3.58293 and 1.33316 ..
 {left}(664.38,570.457) .. tension 3.24976 and 1.83321 ..
 {down}(597.538,540.2) .. tension 1.10758 and 1 ..
 {right}(631.589,536.999) .. tension 1 and 1.61767 ..
 {down}(690,y1) --
 cycle
);
controlledPath (10,0)(_pi)(
z2 {right} .. tension 1.09798 and 1 ..
(443,963) .. tension 3.24976 and 3.31181 ..
 {dir -96}(517,762) --
 cycle
);

%%endpaths
%%beginbody
save _paths; path _paths[];

_paths0 := _pi;
_paths1 := _pii;

_paths2 := subpath(0,length _paths1 - 1) of _paths1;
points0 := point 2 of _paths2;

_paths3 := reverse _paths2 reflectedabout (z1, z1 + (10,0));

_paths4 :=  _paths2 .. controls postcontrol 0 of _paths3 and precontrol 1 of _paths3 .. subpath(1, length _paths3) of _paths3;


_paths5 := _paths4 shifted (point length _paths4 of _paths4 - point 0 of _paths4) rotatedaround (point length _paths4 of _paths4,-45);

_paths6 := _paths4 shifted -(point length _paths4 of _paths4 - point 0 of _paths4) rotatedaround (point 0 of _paths4,45);

_paths7 := subpath(0,1) of _paths0  .. controls postcontrol 1 of _paths0 and precontrol 2 of _paths0 .. point 0 of _paths6;

_paths8 :=  reverse _paths7 reflectedabout (z1, z1 + (10,0));

_paths10 :=  _paths7 & _paths6 & _paths4 & _paths5 .. _paths8;

fill _paths10 .. reverse _paths10 reflectedabout (z2, z2 + (0,10)) .. cycle ;

_paths11 := _piii; _paths12 := reverse subpath(0,length _paths11 - 1) of _paths11;

_paths13 :=  _paths12 .. reverse _paths12 reflectedabout (z2, z2 + (0,10)) .. cycle ; fill _paths13; fill reverse _paths13 reflectedabout (z1, z1 + (10,0));

_paths14 := _piv; _paths15 := subpath(0,length _paths14 - 1) of _paths14; _paths16 := _paths15 .. reverse _paths15 reflectedabout (z1, z1 + (10,0)) .. cycle;

z3 = (x2,y1);

fill _paths16;fill _paths16 rotatedaround (z3, 180);

fill _paths16 rotatedaround (z3, 45); fill _paths16 rotatedaround (z3, -45);
fill _paths16 rotatedaround (z3, 135); fill _paths16 rotatedaround (z3, -135);

fill fullcircle scaled 130  shifted z3;
fill fullcircle scaled 260  shifted z3;
currentpicture := currentpicture  shifted (0,-300) scaled 1 ;

endchar;
beginchar(placeofsajdah,1769,-1,-1,-1);
%%backgroundimage:images/sajda.jpg,-1086.5,-1089.55,1,0,0,1

%%beginpaths

fill
(216.976,57.5783) .. tension 1 and 1 ..
 {up}(239.326,92.239) .. tension 1 and 1 ..
 {up}(231.626,330.504) .. tension 10.3117 and 0.75 ..
 {up}(148.276,406.314) .. tension 1.03636 and 1.34025 ..
(307.999,562.339) .. tension 1 and 5.21582 ..
 {right}(335.697,626.688) .. tension 7.853 and 1 ..
(372.178,563.172) .. tension 1.23371 and 1.00181 ..
 {down}(539.931,417.245) .. tension 0.762728 and 6.87108 ..
 {down}(471.644,347.801) .. tension 1 and 1.34752 ..
 {down}(481.288,135.513) .. tension 0.916134 and 2.79655 ..
 {down}(521.656,81.2328) .. tension 12.0083 and 5.3958 ..
(365.1,62.441) .. tension 5.4814 and 11.064 ..
 {up} cycle
;
fill
(338.381,571.47) .. tension 7.79178 and 1 ..
(301.33,533.158) .. tension 1 and 1 ..
 {down}(167.583,403.485) .. tension 0.777617 and 3.94323 ..
 {down}(247.221,339.662) .. tension 1 and 1 ..
 {down}(256.03,116.042) .. tension 1 and 1.41754 ..
 {down}(251.419,71.0595) .. tension 13.6448 and 2.41969 ..
(369.571,74.3808) .. tension 2.18139 and 10.3562 ..
 {up}(481.315,90.3108) .. tension 0.75 and 1 ..
 {up}(463.543,131.637) .. tension 2.66531 and 1 ..
 {up}(453.64,353.733) .. tension 3.40012 and 0.851637 ..
 {up}(517.216,410.317) .. tension 1 and 1.00683 ..
(375.719,536.485) .. tension 1 and 3.10649 ..
 {left} cycle
;
fill
(220.441,402.636) .. tension 1.86077 and 1 ..
(287.454,462.159) .. tension 1 and 2.92388 ..
 {right}(339.698,505.529) .. tension 2.39921 and 1 ..
(394.901,465.787) .. tension 1 and 1.7426 ..
 {down}(469.415,413.041) .. tension 0.978867 and 2.43577 ..
 {down}(417.361,370.486) .. tension 1 and 1 ..
 {down}(432.577,141.494) .. tension 3.59482 and 0.933838 ..
(358.91,126.914) .. tension 1 and 6.52764 ..
 {up}(292.399,127.183) .. tension 1 and 1 ..
 {up}(278.803,362.248) .. tension 3.25519 and 1.12185 ..
 {up} cycle
;

%%endpaths
%%beginbody
leftbearing:=0;
rightbearing:=100;
endchar;
defchar(endofaya,1757,-1,-1,-1);
%%backgroundimage:images/aya2.JPG,-205.054,-919.225,1,0,0,1
%%beginparams
thickness_ := 20;
z1 = (441,727);
z1.n1 = (xpart.z1,-273);
z1.n2 = (xpart.z1,-249);
z1.n3 = (xpart.z1,-154);
z1.n4 = (xpart.z1,ypart.z1.n3 + thickness_);
z1.n5 = (xpart.z1,ypart.z1 - thickness_);
z2 = (440,786);
z3 = (882,282);

%%beginverbatim

%%endverbatim

%%beginpaths

fill
z1 ..
 {dir 0}(467,725) {dir 140.227} ..
 {up}z2 ..
 {right}(530,873) ..
 {down}(623,ypart.z2) ..
 {dir -133.736}(607,741) {dir -11.7662} .. tension 0.906888 and 1 ..
 {dir -38.019}(780,665) {dir 75.9387} .. tension 0.984617 and 1.1724 ..
 {dir 9.32696}(851,746) {dir -92.5571} .. tension 1.17576 and 1 ..
(897,613) .. tension 1 and 1.45857 ..
 {dir -58.1711}(987,523) {dir 34.7492} .. tension 0.760681 and 1.19379 ..
 {dir 6.52681}(1058,542) {dir -116.849} .. tension 0.920526 and 1 ..
 {down}(1029,413) .. tension 1 and 1 ..
(1036,262) .. tension 1 and 1 ..
 {left}(1003,246) .. tension 1 and 0.75 ..
 {dir 141.418}(973,258) {down} ..
 {left}z1.n1 .. tension 1 and 1 ..
 {right}z1.n2 ..
 {up}(953,257) .. tension 1.06633 and 0.764259 ..
 {dir 96.2847}(951,307) {dir -49.7743} ..
 {right}(999,269) ..
 {up}(1008,405) ..
 {dir 61.522}(1028,515) {dir 174.326} .. tension 0.972502 and 1.52367 ..
 {dir -99.1799}(938,419) {dir 90.999} .. tension 0.75354 and 1 ..
(937,471) .. tension 0.965318 and 1.04914 ..
 {dir 48.295}(968,513) {dir 124.83} .. tension 1.47369 and 1 ..
(878,601) .. tension 1 and 0.75 ..
 {dir 102.678}(833,710) {dir -156.685} .. tension 0.956759 and 4.83272 ..
 {dir -70.6238}(801,539) {left} .. tension 4.76661 and 1.27814 ..
 {dir 121.695}(780,565) .. tension 3.64246 and 1.01452 ..
 {dir 85.7017}(776,645) {dir 135.318} .. tension 1.57031 and 1.00182 ..
 {dir 173.721}(575,728) {dir 35.4839} ..
 {up}(602,ypart.z2) ..
 {left}(530,855) ..
 {down}(461,ypart.z2) .. tension 0.975908 and 0.772607 ..
(624,689) .. tension 1.33082 and 1 ..
(786,558) ..
 {down}z3 ..
 {left}z1.n3 ..
 {right}z1.n4 ..
 {up}(xpart.z3 - thickness_,ypart.z3) ..
 {left}z1.n5 ..
 {right} cycle
;

%%endpaths
%%beginbody

path _p[];

_p0 := pathpart currentpicture;

currentpicture := nullpicture;
_p1 := subpath (ypart (z1 intersectiontimes  _p0), ypart ( z1.n1 intersectiontimes  _p0)) of _p0;
fill _p1 .. reverse  (_p1 reflectedabout (z1,z1+(0,50))) .. cycle withcolor black;
_p1 := subpath (ypart (z1.n2 intersectiontimes  _p0), ypart ( z1.n3 intersectiontimes  _p0)) of _p0;
fill _p1 .. reverse  (_p1 reflectedabout (z1,z1+(0,50))) .. cycle withcolor white;
_p1 := subpath (ypart (z1.n4 intersectiontimes  _p0), ypart ( z1.n5 intersectiontimes  _p0)) of _p0;
fill _p1 .. reverse  (_p1 reflectedabout (z1,z1+(0,50))) .. cycle withcolor white;;
savepicture:=1;

currentpicture := currentpicture shifted (0,30) scaled 0.84;

enddefchar;
beginchar(endofaya.ii,-1,-1,-1,-1);
%%backgroundimage:images/hizb.jpg,-1277.59,-1060.2,1,0,0,1
%%beginparams
z1 = (407,1000);

%%beginverbatim

save _color; color _color[];
_color1 := (229.0/255,216.0/255,164.0/255); %dacc8f (yellow)
_color2:= (190.0/255,208.0/255,166.0/255); %bed0a6 (green)
%%endverbatim

%%beginpaths

controlledPath (0,0)(_pi)(
z1 .. tension 1.34662 and 1 ..
(431,960) .. tension 2.17161 and 1 ..
(505.307,881) .. tension 1 and 1 ..
(709.307,780) .. tension 0.75 and 1 ..
(903.307,652) .. tension 1 and 2.06235 ..
 {down}(963.443,607) .. tension 2.53564 and 1 ..
 {left}(869.926,545.965) .. tension 1 and 1 ..
 {left}(768.114,555.716) .. tension 1 and 1.30863 ..
 {left}(705.837,523.589) .. tension 1.57355 and 1 ..
 {left}(541.041,622) .. tension 1 and 1.6568 ..
 {left}(x1,550) .. tension 3.04005 and 10000 ..
 {right} cycle
);
controlledPath (1,0)(_pii)(
(x1,601.834) .. tension 1 and 1 ..
 {right}(540.452,662) .. tension 1 and 5.79299 ..
 {right}(712.026,573.518) .. tension 1 and 0.75 ..
 {right}(769.11,601) .. tension 1 and 1 ..
 {right}(857.001,586.798) .. tension 1 and 2.67019 ..
 {up}(910,597) .. tension 9.69283 and 1 ..
(697.305,746) .. tension 1 and 1 ..
(442.305,888) .. tension 1 and 2.77377 ..
(x1,930.166) .. tension 3.61131 and 3.89693 ..
 {right} cycle
);
controlledPath (2,0)(_piii)(
(552.296,759.212) .. tension 4.26468 and 1 ..
(637.016,727.431) .. tension 1 and 6.10119 ..
 {down}(720.965,669.876) .. tension 2.36638 and 1.96816 ..
 {left}(691.248,633.295) .. tension 4.5127 and 1 ..
(609.816,681.713) .. tension 1 and 4.54003 ..
 {up}(530.557,718.372) .. tension 2.1223 and 2.35586 ..
 {right} cycle
);

%%endpaths
%%beginbody

path _path[];

z.center2 =  (x1,y1 - 720);

picture _temppic;
_temppic := image(

_path1 := _pi;
_path2 := subpath(0,length _path1 -1) of _path1;
fill _path2 .. (reverse _path2 reflectedabout (z1, z1 + (0,10))) .. cycle;

_path3 := _pii;
_path4 := subpath(0,length _path3 -1 ) of _path3;
fill _path4 .. reverse _path4 reflectedabout (z1, z1 + (0,10)) .. cycle  withcolor _color1;

_path5 := _piii;
fill _path5;
fill _path5 reflectedabout (z1, z1 + (0,10));


z.center =  (x1,ypart point 0 of _path5);
fill fullcircle scaled 125  shifted z.center;

draw currentpicture reflectedabout (z.center2, z.center2 + (10,0));
);

fill fullcircle scaled 1120  shifted z.center2;
fill reverse fullcircle scaled 1030  shifted z.center2 withcolor _color1;
fill fullcircle scaled 940  shifted z.center2;
fill reverse fullcircle scaled 850  shifted z.center2 withcolor _color2;
draw _temppic;
currentpicture := currentpicture  scaled 1.0467;
show currentwidth;
endchar;
defchar(one_dot,-1,-1,-1,-1);
%%backgroundimage:images/one_dot.jpg,-1291.7,-624.115,1,0,0,1

%%beginpaths

fill
(-82.0567,44.0748) .. tension 1.46921 and 2.7974 ..
 {right}(-37.1214,116.969) .. tension 1.36793 and 3.58612 ..
 {down}(38.9892,73.0404) .. tension 0.919075 and 1.75531 ..
 {left}(-5.68558,1.42331) .. tension 1.10332 and 3.96234 ..
 {up} cycle
;

%%endpaths
%%beginbody

%currentpicture := nullpicture;

%save angle;numeric angle;
%angle := 65;



%fill (0,0)  {dir  190}  ..   {dir -190} (-penwidth,0) .. (-penwidth,penwidth) -- (0,penwidth) -- cycle;

%currentpicture := currentpicture rotated angle;


tr_ := identity shifted (0,-ypart llcorner currentpicture);

leftbearing:=0;
savepicture:=1;
enddefchar;
defchar(two_dots,-1,-1,-1,-1);
%%backgroundimage:images/two_dots.jpg,-1644.4,-675.794,1,0,0,1

%%beginpaths

fill
(221.345,41.4588) .. tension 2.01595 and 1.49947 ..
 {right}(277.142,108.37) .. tension 2.17451 and 3.64423 ..
 {right}(340.112,78.018) .. tension 3.75734 and 1.49184 ..
 {right}(388.977,125.502) .. tension 2.89959 and 2.38321 ..
 {down}(451.017,66.9315) .. tension 8.41937 and 3.02118 ..
 {left}(403.414,-0.536878) .. tension 2.54187 and 2.97311 ..
 {left}(346.207,31.7092) .. tension 3.14194 and 2.65824 ..
 {left}(296.514,-9.85648) .. tension 5.07412 and 2.39164 ..
 {up} cycle
;

%%endpaths
%%beginbody


%tr_ := identity shifted (0,-ypart llcorner currentpicture);

leftbearing:=0;
savepicture:=1;
enddefchar;
beginchar(onedotup,-1,-1,-1,-1);
%%beginbody
one_dot_(0,0);
endchar;
beginchar(onedotdown,-1,-1,-1,-1);
%%beginbody
one_dot_(0,0);
endchar;
beginchar(twodotsup,-1,-1,-1,-1);
%%beginbody
two_dots_(0,0);
endchar;
beginchar(twodotsdown,-1,-1,-1,-1);
%%beginbody
two_dots_(0,0);
endchar;
beginchar(three_dots,-1,-1,-1,-1);
%%backgroundimage:images/three_dots.jpg,-857.685,-808.843,1,0,0,1
%%beginparams
z1 = (344.041,110.882);
%%beginbody

two_dots_(0,0);
draw  image(one_dot_(0,0)) shifted z1;

leftbearing := 0;

tr_ := identity shifted (0,-ypart llcorner currentpicture);
endchar;
defchar(minikaf,-1,-1,-1,-1);
%%backgroundimage:images/minikaf.jpg,-101.535,-1117,1,0,0,1

%%beginpaths

fill
(174.982,205.475) .. tension 1.6784 and 1.33888 ..
 {right}(182.536,218.134) .. tension 4.85985 and 2.8036 ..
 {up}(294.117,251.491) .. tension 1.87337 and 0.75 ..
 {up}(192.729,315.2) .. tension 1 and 2.02954 ..
 {right}(322.305,485.91) .. tension 1 and 1.563 ..
 {down}(350.791,457.397) .. tension 1.52995 and 1.31644 ..
 {left}(313.32,394.869) .. tension 1.10481 and 1 ..
 {left}(287.63,401.194) .. tension 1.37215 and 1.6639 ..
 {down}(261.11,363.869) .. tension 1.89793 and 1.04835 ..
 {down}(380.149,304.992) .. tension 1.16642 and 0.75 ..
 {left}(248.892,180.957) .. tension 1 and 2.03546 ..
 {up} cycle
;

%%endpaths
%%beginbody

leftbearing:=0;

tr_ := identity shifted (0,-ypart llcorner currentpicture);
savepicture:=1;
enddefchar;
defchar(fatha,1614,-1,-1,-1);
%%backgroundimage:images/fatha.jpg,-3764.55,-449.571,1,0,0,1
%%beginparams
z1 = (-3.1983,454.645);

%%beginverbatim

lefttatweel := lefttatweel - 0.9;
minLeft := -2;
maxLeft := 5; 
x1 := nuqta * 7;

%%endverbatim

%%beginpaths

fill
bldmvi ( (-244.829,-6.34112), (0,0) ) .. tension 1.08991 and 1.01388 ..
 {up}bldmvi ( (-259.617,11.0864), (0,0) ) .. tension 0.993599 and 1.54427 ..
bldmvi ( (-255.037,45.4872), (9,5) ) .. tension bldmvi ( 10.8154, 6.2409 ) and 5.91049 ..
bldmvi ( (-221.791,69.3514), (446.537,209.467) ) .. tension 4.06677 and 26.8638 ..
 {right}bldmvi ( (-166.331,112.163), (956.284,454.767) ) .. tension 1.32384 and 1 ..
 {down}bldmvi ( (-149.425,99.85), z1 ) .. tension 0.75 and 2.19215 ..
bldmvi ( (-167.392,49.5615), (955.376,454.356) ) .. tension 14.6732 and 1.55369 ..
bldmvi ( (-214.752,12.0413), (450.75,209.584) ) .. tension 4.27611 and 7.81667 ..
 {left} cycle
;

%%endpaths
%%beginbody


leftbearing := 0;
tr_ := identity shifted (0,-ypart llcorner currentpicture);
savepicture:=1;
enddefchar;
defchar(kasra,1616,-1,-1,-1);
%%beginbody

fatha_(lefttatweel,0);
leftbearing := 0;
rightbearing := 0;
enddefchar;
beginchar(fathatan,1611,-1,-1,-1);
%%beginbody


picture _temppic;
_temppic := image(
fatha_(0,0);
);

draw _temppic;

draw _temppic shifted (0,120);


leftbearing := 0;
rightbearing := 0;
savepicture:=1;
endchar;
defchar(kasratanidgham,2290,-1,-1,-1);
%%beginbody

lefttatweel := lefttatweel - 0.5;
picture _temppic;
_temppic := image(
fatha_(lefttatweel,righttatweel);
);

draw _temppic;

z.ul = ulcorner _temppic;
z.ur = urcorner _temppic;
z.lr = lrcorner _temppic;

draw _temppic shifted (1/3(x.ul - x.ur), -(y.ur-y.lr));
tr_ := identity shifted (0,-ypart llcorner currentpicture);

enddefchar;
beginchar(kasratan,1613,-1,-1,-1);
%%beginbody

leftbearing := rightbearing := 0;
drawcomp(fathatan,identity);



endchar;
defchar(fathatanidgham,2288,-1,-1,-1);
%%backgroundimage:images/fathatanidgham.jpg,-522,-377,1,0,0,1
%%beginbody

lefttatweel := lefttatweel - 0.35;
picture _temppic;
_temppic := image(
fatha_(lefttatweel,righttatweel);
);

draw _temppic;

z.ul = ulcorner _temppic;
z.ur = urcorner _temppic;
z.lr = lrcorner _temppic;

draw _temppic shifted (1.3/3(x.ul - x.ur), -0.90(y.ur-y.lr));

leftbearing := 0;
tr_ := identity shifted (0,-ypart llcorner currentpicture);
savepicture:=1;

enddefchar;
beginchar(damma,1615,-1,-1,-1);
%%backgroundimage:images/damma.jpg,-5083.53,-777.698,1,0,0,1

%%beginpaths

fill
(35.2927,107.784) {up} .. tension 1.81711 and 1 ..
(110.33,179.213) .. tension 1 and 3.16449 ..
 {up}(172.232,239.292) .. tension 9.34695 and 1 ..
 {up}(125.765,304.565) .. tension 1.25258 and 1.20107 ..
 {right}(219.839,421.912) .. tension 1.70126 and 0.861862 ..
 {down}(257.591,344.034) .. tension 1.70513 and 2.78751 ..
 {down}(252.721,295.733) .. tension 3.26562 and 1.29424 ..
 {down}(298.853,229.157) .. tension 1 and 1.63085 ..
 {left}(269.48,186.878) .. tension 1.73346 and 2.26225 ..
 {left}(222.333,213.598) .. tension 3.50563 and 1 ..
(213.97,204.778) .. tension 1.00116 and 2.37559 ..
 {left}(55.6557,97.4304) .. tension 1 and 1 ..
 cycle
;
fill
(180.304,329.12) .. tension 1.89258 and 1.78891 ..
 {right}(208.175,311.337) .. tension 2.58878 and 3.36972 ..
 {left}(196.972,341.607) .. tension 1.6707 ..
 {down} cycle
;

%%endpaths
%%beginbody
leftbearing := 0;
tr_ := identity shifted (0,-ypart llcorner currentpicture);
savepicture:=1;
endchar;
beginchar(dammatanidgham,2289,477,327,-2);
%%backgroundimage:images/dammatan_idgham.jpg,-2679.59,-741.94,1,0,0,1
%%beginbody

drawcomp(damma,identity scaled 0.9 rotated 5);
drawcomp(damma,identity shifted (120,-10));

leftbearing := 0;
rightbearing := 0;
currentpicture := currentpicture shifted (0,-ypart llcorner currentpicture);

endchar;
beginchar(dammatan,1612,-1,-1,-1);
%%backgroundimage:images/dammatan.jpg,-198.336,-518.239,1,0,0,1

%%beginpaths

fill
(66.0926,117.94) .. tension 1.19572 and 1 ..
 {up}(0.212963,191.458) .. tension 1.40674 and 1.21199 ..
 {right}(212.94,450.236) .. tension 1.43613 and 0.75 ..
 {down}(284.25,352.727) .. tension 1 and 1.53071 ..
 {left}(264.144,302.31) .. tension 1.57752 and 0.799644 ..
 {left}(194.991,379.606) .. tension 1.38547 and 1.81931 ..
 {down}(44.3148,219.718) .. tension 1.07796 and 0.997204 ..
 {down}(93.6713,160.255) .. tension 1.24169 and 1.7831 ..
 {left} cycle
;

%%endpaths
%%beginbody

draw damma.pic;

currentpicture := currentpicture shifted (0,-ypart llcorner currentpicture);
leftbearing := 0;
rightbearing := 0;

endchar;
beginchar(shadda,1617,-1,-1,-1);
%%backgroundimage:images/shadda.jpg,-2284,-808,1,0,0,1

%%beginpaths

fill
(21.8522,63.0193) {up} .. tension 1.51543 and 1.50006 ..
 {right}(54.6538,136.026) .. tension 1 and 1 ..
(67.3715,124.593) .. tension 1 and 1.4345 ..
 {right}(81.7527,92.8073) .. tension 0.834662 and 1.19094 ..
(100.303,114.206) .. tension 1 and 1.24873 ..
 {right}(128.826,162.48) .. tension 1.00745 and 1.10739 ..
(144.527,146.602) .. tension 0.85953 and 1 ..
 {right}(157.444,120.531) .. tension 1.19951 and 1.81482 ..
(172.488,151.646) .. tension 1 and 1.2156 ..
 {right}(204.629,191.716) .. tension 0.917097 and 1 ..
 {down}(220.504,161.509) .. tension 0.75 and 1.34885 ..
 {left}(119.78,45.8822) .. tension 4.47151 and 0.75 ..
 {left}(69.4379,16.4368) .. tension 1.33199 and 0.75 ..
 cycle
;

%%endpaths
%%beginbody

tr_ := identity shifted (0,-ypart llcorner currentpicture);
leftbearing := 0;


endchar;
beginchar(headkhah,1761,-1,-1,-1);
%%backgroundimage:images/sukun.jpg,-1381.32,-432.33,1,0,0,1

%%beginpaths

fill
(13.224,93.3958) {up} .. tension 1.5854 and 2.99841 ..
 {right}(104.004,164.041) .. tension 1.29281 and 2.96178 ..
 {down}(223.099,114.697) .. tension 1.10538 and 2.06803 ..
 {left}(66.1541,23.665) .. tension 1 and 1 ..
 {up}(32.0355,43.8536) .. tension 2.58885 and 2.50673 ..
 {up}(103.171,89.8967) .. tension 1.56576 and 2.71315 ..
 {left}(81.9029,96.5057) .. tension 1 and 1.94997 ..
 {left}(30.3859,76.9883) .. tension 1 and 1 ..
 cycle
;

%%endpaths
%%beginbody


tr_ := identity shifted (0,-ypart llcorner currentpicture);

leftbearing := 0;
savepicture:=1;
endchar;
beginchar(sukun,1618,-1,-1,-1);
%%beginbody

draw headkhah.pic;

leftbearing := 0;

endchar;
beginchar(maddahabove,1619,-1,-1,-1);
%%backgroundimage:images/maddahabove.jpg,-29.142,-969.858,1,0,0,1

%%beginpaths

fill
(10.3124,-9.38) {left} .. tension 0.75 and 1 ..
 {up}(0.614356,2.68402) .. tension 1.55029 and 2.02077 ..
 {right}(73.6755,106.065) .. tension 3.67232 and 0.75 ..
 {right}(163.081,85.3347) .. tension 0.75 and 3.72774 ..
 {right}(307.519,147.803) .. tension 1 and 1 ..
 {down}(321.071,136.342) .. tension 1.42218 and 1 ..
 {left}(137.225,12.7288) .. tension 0.75 and 2.76344 ..
 {left}(63.0995,29.3003) .. tension 2.21874 and 1.17659 ..
 cycle
;

%%endpaths
%%beginbody


tr_ := identity shifted (0,-ypart llcorner currentpicture);
leftbearing := 0;

endchar;
beginchar(smallalef,1648,-1,-1,-1);
%%backgroundimage:images/smallalef.jpg,-1916,-898.665,1,0,0,1

%%beginpaths

fill
(113.272,2.68133) .. tension 1.90502 and 0.75 ..
(97.5169,85.2275) .. tension 0.843904 and 2.20207 ..
 {up}(36.3998,195.336) .. tension 1.41235 and 1.21358 ..
 {right}(64.5211,246.776) .. tension 1.77775 and 1.05118 ..
 {down}(155.768,91.9537) .. tension 0.882432 and 1.47334 ..
 {left} cycle
;

%%endpaths
%%beginbody

tr_ := identity shifted (0,-ypart llcorner currentpicture);
leftbearing := 0;

savepicture:=1;
endchar;
beginchar(smallalef.joined,-1,-1,-1,-1);
%%beginbody
draw smallalef.pic;
leftbearing := 0;


endchar;
beginchar(smallalef.isol,-1,-1,-1,-1);
%%beginbody


draw smallalef.pic  shifted (0,150);



endchar;
beginchar(smallalef.replacement,-1,-1,-1,-1);
%%beginbody
draw smallalef.pic;
leftbearing := 0;
endchar;
beginchar(wasla,-1,-1,-1,-1);
%%backgroundimage:images/wasla.jpg,-2152,-311,1,0,0,1

%%beginpaths

fill
(18.8744,-2.79016) {left} .. tension 0.75 and 1 ..
 {up}(6.96798,12.1203) .. tension 1.71327 and 2.55661 ..
(100.228,105.542) .. tension 0.937351 and 1.19184 ..
(137.376,113.6) .. tension 4.12537 and 0.92527 ..
 {right}(254.991,205.443) .. tension 0.980342 and 1 ..
 {down}(309.981,155.709) .. tension 1.27113 and 1.05341 ..
(267.808,72.4285) .. tension 1.67088 and 1 ..
 {left}(145.21,18.7859) .. tension 0.75 and 1.40058 ..
 {left}(94.674,39.0656) .. tension 0.844428 and 1.92764 ..
 cycle
;
fill
(184.058,100.543) {down} .. tension 2.16927 and 0.75 ..
 {right}(190.368,96.1932) .. tension 7.59176 and 1.09046 ..
 {up}(240.332,123.258) .. tension 3.01504 and 1.01267 ..
 {left}(217.352,130.824) .. tension 1.73078 and 1.62295 ..
 cycle
;

%%endpaths
%%beginbody


tr_ := identity shifted (0,-ypart llcorner currentpicture);
leftbearing := 0;


endchar;
beginchar(meemiqlab,1762,-1,-1,-1);
%%backgroundimage:images/meemiqlab.jpg,-9,-1438,1,0,0,1

%%beginpaths

fill
(126.972,447.154) .. tension 1.69855 and 2.43993 ..
 {down}(206.489,362.969) .. tension 1 and 1 ..
(171.514,308.075) .. tension 2.62213 and 2.21235 ..
(91.0065,292.53) .. tension 0.902226 and 1.94588 ..
(68.8724,246.908) .. tension 5.89108 and 0.75 ..
 {down}(91.6434,96.6531) .. tension 1 and 1.52359 ..
 {left}(64.4589,25.5594) .. tension 1.53131 and 1 ..
 {up}(49.1979,68.9622) .. tension 1 and 1 ..
(40.7188,133.334) .. tension 1 and 1.06711 ..
 {up}(24.1207,249.815) .. tension 1 and 1.1013 ..
(44.2288,312.089) .. tension 1 and 1.91173 ..
 {up}(61.9717,339.577) .. tension 1.5443 and 1 ..
 {up}(55.6596,354.414) .. tension 1 and 1.67214 ..
 {right} cycle
;

%%endpaths
%%beginbody

leftbearing := 0;


tr_ := identity shifted (0,-ypart llcorner currentpicture);
savepicture:=1;
endchar;
beginchar(smalllowmeem,1773,-1,-1,-1);
%%beginbody

draw meemiqlab.pic;


tr_ := identity shifted (0,-ypart llcorner currentpicture);
leftbearing := 0;



endchar;
beginchar(smallwaw,1765,-1,-1,-1);
%%backgroundimage:images/smallwaw.jpg,-1330,-1108,1,0,0,1

%%beginpaths

fill
(-190.862,-14.2614) .. tension 0.91242 and 1.19701 ..
 {right}(-159.44,2.68663) .. tension 0.805986 and 3.24814 ..
 {up}(-55.8869,63.6326) .. tension 1 and 1 ..
 {left}(-58.6106,65.7504) .. tension 3.51137 and 0.983038 ..
 {left}(-73.4907,62.7765) .. tension 1.19681 and 0.894623 ..
 {up}(-119.162,120.216) .. tension 1.11908 and 1.94733 ..
 {right}(-62.715,196.112) .. tension 2.09946 and 0.907097 ..
 {down}(-4.49998,101.107) .. tension 1.28638 and 1.00925 ..
 {left}(-132.378,-42.1265) .. tension 1 and 2.82242 ..
 {up} cycle
;
fill
(-71.1948,131.43) .. tension 1.36971 and 1.34334 ..
 {down}(-77.3914,124.863) .. tension 0.994166 and 1 ..
 {right}(-70.1028,117.056) .. tension 1.29574 and 1.19944 ..
 {up}(-64.6036,125.512) .. tension 1.12113 and 1.74687 ..
 {left} cycle
;

%%endpaths
%%beginbody
savepicture:=1;
endchar;
beginchar(smallhighwaw,2291,-1,-1,-68);
%%beginbody

draw smallwaw.pic;


tr_ := identity shifted (0,-ypart llcorner currentpicture);
leftbearing := 0;

endchar;
defchar(smallyeh,1766,-1,-1,-1);
%%backgroundimage:images/smallyeh.jpg,-445,-1183,1,0,0,1

%%beginpaths

fill
(-351.762,69.3037) .. tension 1.48976 and 0.906448 ..
(-289.096,146.957) .. tension 1 and 1 ..
(-219.979,178.407) .. tension 1 and 1.01664 ..
 {right}(-159.408,227.404) .. tension 2.01433 and 1 ..
 {down}(-130.569,176.961) .. tension 1 and 1.29746 ..
 {left}(-148.413,134.909) .. tension 0.789225 and 1 ..
 {left}(-175.612,162.686) .. tension 2.18655 and 1 ..
(-238.948,115.909) .. tension 0.783049 and 2.29178 ..
 {down}(-291.065,92.0932) .. tension 4.99297 and 1 ..
 {right}(-143.96,77.5814) .. tension 1 and 1.4289 ..
 {right}(-53.2837,79.5635) .. tension 1 and 1 ..
 {down}(-39.8091,65.5603) .. tension 3.82839 and 1 ..
 {left}(-257.622,25.8854) .. tension 0.813862 and 1.67169 ..
 {up} cycle
;

%%endpaths
%%beginbody

enddefchar;
beginchar(smallhighyeh,1767,-1,-1,-1);
%%beginbody

smallyeh_(0,0);
leftbearing := 0;
rightbearing := 0;
currentpicture := currentpicture shifted (0,-ypart llcorner currentpicture);

endchar;
beginchar(smallhighroundedzero,1759,-1,-1,-1);
%%backgroundimage:images/smallhighroundedzero.jpg,3.44778,-460.991,1,0,0,1

%%beginpaths

fill
(34.1917,66.4706) .. tension 1.34736 and 1.57425 ..
 {right}(126.155,212.168) .. tension 0.976859 and 1 ..
 {down}(195.194,133.831) .. tension 1.53049 and 0.891469 ..
 {left}(87.4753,14.4676) .. tension 0.948643 and 1 ..
 {up} cycle
;
fill
(120.279,137.348) .. tension 0.89884 and 3.22329 ..
 {down}(90.1867,102.173) .. tension 1.2509 and 0.934632 ..
 {right}(105.828,88.2415) .. tension 0.891567 and 0.959127 ..
 {up}(135.103,111.197) .. tension 1.40535 and 0.988679 ..
 {left} cycle
;

%%endpaths
%%beginbody


tr_ := identity shifted (0,-ypart llcorner currentpicture);
leftbearing := 0;



endchar;
beginchar(rectangularzero,1760,-1,-1,-1);
%%backgroundimage:images/rectangularzero.jpg,-42.2738,-617.656,1,0,0,1

%%beginpaths

fill
(34.4869,99.6699) .. tension 0.919879 and 0.968557 ..
 {right}(129.244,212.76) .. tension 0.905663 and 1 ..
 {down}(224.976,104.035) .. tension 0.993144 and 0.908861 ..
 {left}(132.919,2.6765) .. tension 0.93535 and 1 ..
 {up} cycle
;
fill
(124.626,174.229) .. tension 1.12485 and 1 ..
 {down}(91.8821,100.24) .. tension 1 and 0.911308 ..
 {right}(134.136,37.4536) .. tension 1.14783 and 1 ..
 {up}(166.456,101.3) .. tension 1 and 1.10249 ..
 {left} cycle
;

%%endpaths
%%beginbody

tr_ := identity shifted (0,-ypart llcorner currentpicture);
leftbearing := 0;


endchar;
beginchar(roundedfilledhigh,1772,-1,-1,-1);
%%backgroundimage:images/roundedfilledhigh.jpg,-1994,-324,1,0,0,1
%%beginbody

fill fullcircle scaled 200;
tr_ := identity shifted (0,-ypart llcorner currentpicture);
leftbearing := 0;


savepicture:=1;
endchar;
beginchar(roundedfilledlow,1628,-1,-1,-1);
%%backgroundimage:images/lozengebelow.jpg,-1056,-1669,1,0,0,1
%%beginparams
z1 = (104.472,338.421);
z2 = (0.736111,160.63);

%%beginpaths

fill
z2 .. tension 7.9023 and 2.34237 ..
 {right}z1 .. tension 2.60725 and 8.09865 ..
 {down}(220.454,y2) .. tension 4.29417 and 4.83028 ..
 {left}(x1,-2.4213) .. tension 2.97641 and 9.19197 ..
 {up} cycle
;
fill
(175.255,y2) .. tension 3.53665 and 5.44671 ..
 {left}(x1,274.473) .. tension 3.59146 and 2.48763 ..
 {down}(49.2268,y2) .. tension 2.34958 and 4.04801 ..
 {right}(x1,66.6296) .. tension 3.88101 and 11.8111 ..
 {up} cycle
;

%%endpaths
%%beginbody
tr_ := identity shifted (0,-ypart llcorner currentpicture);
endchar;
beginchar(hamzaabove,1620,-1,-1,-1);
%%backgroundimage:images/hamzabove.jpg,-1947.32,-400.489,1,0,0,1

%%beginpaths

fill
(50.4629,34.6395) .. tension 1.94543 and 1.21693 ..
 {up}(9.97809,66.5629) .. tension 1.68319 and 1.75473 ..
 {right}(137.395,187.951) .. tension 1.32853 and 1.3809 ..
 {down}(197.562,138.25) .. tension 0.969619 and 1.45415 ..
 {left}(160.172,102.468) .. tension 0.948252 and 1.25853 ..
 {left}(103.287,118.945) .. tension 1.58683 and 1.32613 ..
 {down}(95.4731,109.515) .. tension 2.20344 and 0.75 ..
 {right}(170.673,82.971) .. tension 1 and 5.10949 ..
 {right}(232.713,94.654) .. tension 1 and 1.34611 ..
 {down}(253.198,75.0091) .. tension 1.69061 and 1 ..
(94.7661,-0.88478) .. tension 1 and 5.54159 ..
 {left}(41.2176,-24.3757) .. tension 1 and 1 ..
 {up}(31.5636,-14.3155) .. tension 0.75 and 2.84742 ..
 {up} cycle
;

%%endpaths
%%beginbody

leftbearing := 0;

tr_ := identity shifted (0,-ypart llcorner currentpicture);
savepicture:=1;
endchar;
beginchar(hamzabelow,1621,-1,-1,-1);
%%beginbody
draw hamzaabove.pic;
leftbearing := 0;

endchar;
beginchar(hamzaabove.joined,-1,-1,-1,-1);
%%beginbody

draw hamzaabove.pic;

leftbearing := 0;

endchar;
beginchar(hamzaabove.lamalef,-1,-1,-1,-1);
%%backgroundimage:images/hamza_lam_alef.jpg,-1325.02,-598.109,1,0,0,1

%%beginpaths

fill
(54.1552,11.2836) .. tension 4.05069 and 0.79596 ..
 {up}(21.6102,59.5859) .. tension 1.68319 and 1.75473 ..
 {right}(128.547,179.646) .. tension 1.32853 and 1.3809 ..
 {down}(174.257,141.926) .. tension 0.969619 and 1.83974 ..
 {left}(134.229,87.4194) .. tension 0.948252 and 1.51749 ..
(118.694,97.0532) .. tension 1.62132 and 0.990224 ..
 {left}(98.1531,105.229) .. tension 1.58683 and 1.32613 ..
 {down}(90.111,92.8803) .. tension 3.74267 and 0.75 ..
 {right}(147.931,68.6314) .. tension 1.7937 and 5.10949 ..
 {right}(219.666,86.7899) .. tension 1 and 1.34611 ..
 {down}(244.838,69.016) .. tension 0.983366 and 3.68956 ..
 {left}(194.912,25.6026) .. tension 13.6464 and 1 ..
(125.392,5.38524) .. tension 1 and 5.54159 ..
 {left}(60.9278,-32.3589) .. tension 1 and 1 ..
 {up}(45.6505,-14.3163) .. tension 0.75 and 0.882608 ..
 {up} cycle
;

%%endpaths
%%beginbody

leftbearing := 0;

tr_ := identity shifted (0,-ypart llcorner currentpicture);
savepicture:=1;
endchar;
beginchar(hamzaabove.small,-1,-1,-1,-1);
%%beginbody
draw hamzaabove.lamalef.pic;
leftbearing := 0;
endchar;
beginchar(waqf.lam,1753,-1,-1,-1);
%%backgroundimage:images/waqf_lam.jpg,-223.69,-421,1,0,0,1

%%beginpaths

fill
(-103.13,14.556) .. tension 1 and 1.33418 ..
 {right}(-90.4944,65.3024) .. tension 1 and 1 ..
 {right}(-52.8636,65.3024) .. tension 1.66252 and 6.98176 ..
 {up}(-19.0865,106.029) .. tension 2.19471 and 2.16115 ..
(-122.113,217.831) .. tension 1 and 1.46757 ..
 {left}(-142.716,216.436) .. tension 2.29986 and 1 ..
(-192.407,245.371) .. tension 1 and 1 ..
 {up}(-199.9,285.88) .. tension 1 and 1 ..
 {right}(-167.971,317.13) .. tension 1.24772 and 15.008 ..
 {right}(11.4543,160.301) .. tension 4.41418 and 1 ..
(26.6137,229.115) .. tension 1 and 1 ..
(37.7523,315.458) .. tension 1.35436 and 1.35436 ..
 {right}(66.4694,346.491) .. tension 2.44291 and 1 ..
(76.6745,332.323) .. tension 1 and 1 ..
(79.5635,297.603) .. tension 1 and 1 ..
 {down}(94.6287,259.615) .. tension 0.75 and 1.69254 ..
(66.8884,223.806) .. tension 2.73491 and 2.10659 ..
(51.5478,171.624) .. tension 1 and 4.73915 ..
 {down}(36.9369,109.343) .. tension 6.17732 and 0.899064 ..
 {down}(45.9553,50.8348) .. tension 0.75 and 0.75 ..
 {left}(-5.09471,0) .. tension 1 and 2.16338 ..
 {up} cycle
;

%%endpaths
%%beginbody


leftbearing := 0;
rightbearing := 0;

currentpicture := currentpicture shifted (0,-ypart llcorner currentpicture);
endchar;
beginchar(waqf.qaf,1751,-1,-1,-1);
%%backgroundimage:images/waqf.qaf.jpg,-25.3252,-583.271,1,0,0,1

%%beginpaths

fill
(15.8842,55.148) {up} .. tension 1.24719 and 1 ..
(74.7894,145.845) .. tension 0.75 and 2.54464 ..
 {up}(117.867,193.467) .. tension 2.47951 and 2.60219 ..
(111.757,247.383) .. tension 1.78333 and 1.26233 ..
 {up}(90.0445,334.778) .. tension 3.12678 and 0.75 ..
 {right}(112.078,360.789) .. tension 1.51643 and 1.36811 ..
(140.569,312.207) .. tension 1.40421 and 1.38637 ..
 {right}(213.456,156.06) .. tension 1 and 1.59292 ..
 {up}(232.064,161.798) .. tension 2.25361 and 0.75 ..
 {left}(227.027,165.153) .. tension 1.64758 and 1 ..
 {up}(187.403,201.181) .. tension 0.870181 and 1.4673 ..
 {right}(236.114,276.195) .. tension 1.88375 and 1.03083 ..
 {down}(308.158,180.56) .. tension 0.827197 and 1.38508 ..
 {left}(213.719,103.526) .. tension 0.75 and 5.07266 ..
 {left}(141.015,141.001) .. tension 7.9402 and 3.15898 ..
 {down}(65.24,79.4541) .. tension 0.812443 and 1 ..
 {right}(73.9993,69.056) .. tension 2.17311 and 1 ..
(177.903,84.3671) .. tension 1 and 7.0817 ..
 {right}(323.557,104.267) .. tension 0.915482 and 1.22131 ..
 {down}(352.673,85.2355) .. tension 1.4337 and 2.8957 ..
(330.765,57.3989) .. tension 8.56989 and 1.55508 ..
 {left}(40.1996,22.1972) .. tension 0.895201 and 1.3358 ..
 cycle
;
fill
(162.899,329.493) .. tension 0.821128 and 3.85973 ..
 {right}(189.102,359.072) .. tension 2.71049 and 0.75 ..
 {right}(207.259,357.415) .. tension 2.16889 and 0.876023 ..
 {right}(247.139,371.938) .. tension 1.08481 and 1.39936 ..
 {down}(278.186,348.376) .. tension 1.67243 and 0.751095 ..
 {left}(255.924,315.96) .. tension 1.0955 and 0.912023 ..
 {left}(224.241,319.039) .. tension 1.26372 and 0.983061 ..
 {left}(195.23,302.38) .. tension 1.30948 and 1.31763 ..
 {up} cycle
;

%%endpaths
%%beginbody

leftbearing := 0;

tr_ := identity shifted (0,-ypart llcorner currentpicture);




endchar;
beginchar(waqf.jeem,1754,287,1199,0);
%%backgroundimage:images/waqf.jeem.jpg,-203.864,-558.39,1,0,0,1

%%beginpaths

fill
(52.7022,263.698) {left} .. tension 0.75 and 1.30985 ..
 {up}(36.3401,277.059) .. tension 1.71013 and 1 ..
(62.5046,314.454) .. tension 0.94239 and 1 ..
 {right}(98.2271,331.16) .. tension 1.43533 and 8.55717 ..
(197.791,327.971) {right} .. tension 2.79461 and 2.79461 ..
 {right}(256.05,329.543) .. tension 1 and 1 ..
 {down}(281.984,309.78) .. tension 1.34385 and 2.29697 ..
(243.384,274.57) .. tension 7.05297 and 0.75 ..
(123.572,240.488) .. tension 1 and 1.05658 ..
 {down}(79.321,153.329) .. tension 0.759606 and 1.80754 ..
(131.323,85.1983) .. tension 1.60486 and 0.96405 ..
 {right}(293.572,73.4765) .. tension 1 and 1 ..
 {down}(316.144,57.4685) .. tension 2.59706 and 1.17328 ..
 {left}(176.949,19.9752) .. tension 0.881513 and 0.979019 ..
 {up}(32.954,134.562) .. tension 0.75 and 32.0185 ..
 {up}(81.6856,270.576) .. tension 1 and 1 ..
 {left}(77.3177,274.218) .. tension 2.13991 and 0.969572 ..
 cycle
;
fill
(138.339,171.256) {up} .. tension 0.768601 and 3.00849 ..
 {right}(174.38,206.701) .. tension 2.41423 and 1.74654 ..
 {down}(217.314,167.007) .. tension 1.02932 and 3.87913 ..
 {left}(191.955,135.247) .. tension 0.872659 and 2.41511 ..
 cycle
;

%%endpaths
%%beginbody
tr_ := identity shifted (-xpart llcorner currentpicture,-ypart llcorner currentpicture);
leftbearing := 0;


endchar;
beginchar(waqf.sad,1750,-1,-1,-1);
%%backgroundimage:images/waqf.sad.jpg,-46.4403,-438.675,1,0,0,1

%%beginpaths

fill
(10.7778,66.2609) {up} .. tension 1 and 1 ..
(22.9466,101.546) .. tension 0.85553 and 2.93269 ..
(97.5203,177.394) .. tension 1.68752 and 1 ..
(94.8253,223.472) .. tension 1 and 1 ..
 {up}(84.7446,336.039) .. tension 0.958643 and 1.51082 ..
 {right}(102.814,361.246) .. tension 2.48925 and 1 ..
(134.953,239.753) .. tension 1 and 1.36259 ..
 {right}(190.324,146.934) .. tension 0.75 and 1.99157 ..
 {right}(246.397,179.656) .. tension 1.4542 and 0.761481 ..
 {right}(289.429,163.597) .. tension 5.74358 and 1.14238 ..
 {right}(403.966,237.667) .. tension 0.987815 and 1 ..
 {down}(467.584,191.435) .. tension 1.23767 and 1.16528 ..
 {left}(341.113,100.773) .. tension 0.75 and 2.0234 ..
 {left}(245.53,120.456) .. tension 1.93451 and 1 ..
 {left}(190.237,97.7909) .. tension 0.75 and 1.52062 ..
(137.06,121.789) .. tension 1 and 1.17692 ..
 {left}(118.778,137.112) .. tension 3.70259 and 2.86571 ..
 {down}(51.2227,76.4045) .. tension 1.56021 and 1 ..
 {right}(72.2645,64.3863) .. tension 2.52275 and 1 ..
(221.927,70.5075) .. tension 2.20236 and 2.02512 ..
 {right}(430.678,94.7117) .. tension 1.039 and 1.02739 ..
 {down}(463.832,76.5466) .. tension 1.32678 and 1.06615 ..
(451.851,49.5109) .. tension 29.3902 and 2.30418 ..
 {left}(88.6134,11.9922) .. tension 1.18081 and 1 ..
 cycle
;
fill
(354.215,159.794) {down} .. tension 0.847784 and 0.854938 ..
 {right}(359.708,153.326) .. tension 1.45598 and 2.68172 ..
 {up}(415.745,178.195) .. tension 1.01914 and 1.4545 ..
 {left}(398.705,187.625) .. tension 1.51314 and 2.60168 ..
 cycle
;

%%endpaths
%%beginbody


tr_ := identity shifted (0,-ypart llcorner currentpicture);
leftbearing := 0;


endchar;
beginchar(waqf.smallhighthreedots,1755,-1,-1,-1);
%%backgroundimage:images/waqf.smallhighthreedots.jpg,-64,-296,1,0,0,1

%%beginpaths

fill
(-1,-129) .. tension 1 and 1 ..
 {right}(67,-60) .. tension 1 and 1 ..
 {down}(138,-125.604) .. tension 1 and 1 ..
 {up} cycle
;
fill
(84,2.17658) .. tension 1 and 1 ..
 {right}(154,74.1766) .. tension 1 and 1 ..
 {down}(226,8.17658) .. tension 1 and 1 ..
 {left}(156,-64.8234) .. tension 1.09836 and 1 ..
 cycle
;
fill
(182,-123.823) .. tension 1.02885 and 1 ..
 {right}(256,-51.8234) .. tension 1 and 1 ..
 {down}(329,-115.823) .. tension 1 and 1 ..
 {left}(251,-190.823) .. tension 1 and 1 ..
 {up} cycle
;

%%endpaths
%%beginbody


leftbearing := 0;

tr_ := identity shifted (0,-ypart llcorner currentpicture);
endchar;
beginchar(waqf.meem,1752,-1,-1,-1);
%%backgroundimage:images/waqf.meem.jpg,8.32626,-486.999,1,0,0,1

%%beginpaths

fill
(27.0393,34.1135) .. tension 2.6939 and 1.17262 ..
(182.25,170.573) .. tension 1 and 1 ..
(194.988,210.34) .. tension 4.7002 and 1.66052 ..
 {right}(276.346,328.302) .. tension 2.40446 and 1.16079 ..
 {down}(370.491,200.814) .. tension 0.75 and 1.50035 ..
 {left}(290.499,136.362) .. tension 1.42559 and 4.26431 ..
 {left}(249.562,142.969) .. tension 1.33811 and 1 ..
(232.025,129.079) .. tension 0.75 and 1.46117 ..
(202.348,82.4697) .. tension 1.94703 and 2.42739 ..
 {left}(89.8385,16.3638) .. tension 0.75 and 1.75864 ..
 {up} cycle
;

%%endpaths
%%beginbody

tr_ := identity shifted (0,-ypart llcorner currentpicture);
leftbearing := 0;
endchar;
beginchar(smallhighseen,1756,-1,-1,-1);
%%backgroundimage:images/smallhighseen.jpg,-998.843,-529.421,1,0,0,1

%%beginpaths

fill
(31.1214,209.025) .. tension 0.806708 and 2.48753 ..
 {right}(86.9985,310.523) .. tension 1 and 0.75 ..
 {down}(101.69,289.577) .. tension 0.928308 and 1 ..
 {down}(79.5718,233.363) .. tension 1.39509 and 1.06837 ..
 {right}(193.142,152.922) .. tension 1.50602 and 1.90125 ..
 {up}(309.414,214.571) .. tension 0.816419 and 2.3544 ..
 {up}(273.57,313.268) .. tension 1 and 1.57431 ..
 {right}(300.364,361.996) .. tension 1.49083 and 0.75 ..
 {right}(368.938,305.501) .. tension 0.75 and 1.08892 ..
(403.822,340.198) .. tension 1.55499 and 1.19812 ..
 {right}(445.022,379.549) .. tension 1.28054 and 1 ..
 {down}(460.836,366.645) .. tension 2.35846 and 1.27829 ..
 {right}(465.78,317.573) .. tension 2.83282 and 1 ..
(479.955,366.093) .. tension 1 and 1.41665 ..
 {right}(499.228,387.517) .. tension 1.91023 and 1 ..
 {down}(525.013,341.741) .. tension 1 and 0.999 ..
 {left}(472.045,246.753) .. tension 1 and 0.75 ..
 {left}(425.134,258.306) .. tension 1.3261 and 2.87373 ..
(356.26,232.427) .. tension 1.295 and 1 ..
(348.829,202.636) .. tension 1.01911 and 1.35297 ..
 {left}(173.381,87.474) .. tension 1.101 and 1 ..
 {up} cycle
;

%%endpaths
%%beginbody
tr_ := identity shifted (0,-ypart llcorner currentpicture);

leftbearing := 0;

savepicture:=1;
endchar;
beginchar(smalllowseen,1763,-1,-1,-1);
%%beginbody
draw smallhighseen.pic;
leftbearing := 0;


endchar;
beginchar(smallhighnoon,1768,-1,-1,-1);
%%backgroundimage:images/smallhighnoon.jpg,-1519.07,-1083.08,1,0,0,1

%%beginpaths

fill
(38.098,83.4298) .. tension 0.75 and 2.89397 ..
 {right}(99.6223,216.569) .. tension 1 and 1 ..
 {down}(118.082,195.123) .. tension 1 and 1 ..
 {down}(94.2323,127.508) .. tension 1 and 1 ..
 {right}(158.15,88.6836) .. tension 1.22788 and 1.80911 ..
 {up}(265.682,139.778) .. tension 1 and 2.17415 ..
 {up}(221.22,208.186) .. tension 1 and 1.33951 ..
 {right}(248.768,273.564) .. tension 2.57237 and 1 ..
 {down}(322.302,163.139) .. tension 0.75 and 2.17301 ..
 {left}(149.209,4.62963) .. tension 1 and 1.02896 ..
 {up} cycle
;
fill
(88.3058,343.445) .. tension 1 and 0.973624 ..
 {right}(128.973,406.273) .. tension 3.33203 and 1.38704 ..
 {down}(187.316,357.721) .. tension 1 and 1.29698 ..
 {left}(149.882,305.589) .. tension 3.51287 and 1.95394 ..
 {up} cycle
;

%%endpaths
%%beginbody



tr_ := identity shifted (0,-ypart llcorner currentpicture);

leftbearing := 0;


endchar;
defchar(noonshape.isol,-1,-1,-1,-1);
%%backgroundimage:images/noon_isol2.jpg,-27,-1208,1,0,0,1
%%beginparams
z.rjoin = (483.13,210.832);

%%beginpaths

fill
(226.197,-130.532) .. tension 0.826526 and 0.960362 ..
 {up}(50.1825,33.1947) .. tension 1.35039 and 1.76007 ..
 {right}(140.075,205.595) .. tension 0.75 and 1.12749 ..
 {down}(157.6,183.423) .. tension 1.80193 and 0.75 ..
 {down}(117.788,53.0188) .. tension 1.30132 and 0.75 ..
 {right}(256.328,-31.0368) .. tension 1.32488 and 2.26811 ..
 {up}(465.819,50.3505) .. tension 0.893232 and 3.17992 ..
 {up}(392.801,253.426) .. tension 6.32194 and 1.6036 ..
 {right}(430.175,317.252) .. tension 4.75112 and 0.805273 ..
 {down}(521.266,97.8854) .. tension 1.13331 and 0.956441 ..
(486.897,-23.4651) .. tension 0.985502 and 1.18217 ..
 {left} cycle
;

%%endpaths
%%beginbody


setCursiveAnchor(rtlcursive,z.rjoin, EntryAnchorRTL);
enddefchar;
defchar(noonshape.fina,-1,-1,-1,-1);
%%backgroundimage:images/noon.fina.jpg,38.3255,-1034.99,1,0,0,1
%%beginparams
rightVerticalRatioNeg := 100;

%%beginverbatim

righttatweel := righttatweel - 0.5;

%%endverbatim

%%beginpaths

fill
(248.642,-221.865) .. tension 0.826526 and 0.960362 ..
 {up}(75.4047,-53.972) .. tension 1.35039 and 2.92755 ..
 {right}(162.52,100.373) .. tension 0.75 and 1.12749 ..
 {down}(180.739,75.4229) .. tension 5.01017 and 0.75 ..
 {down}(146.483,-14.7034) .. tension 1.05712 and 0.75 ..
 {right}(287.8,-122.371) .. tension 1.26404 and 1.12703 ..
 {up}(474.188,-16.1554) .. tension 0.868291 and 2.41803 ..
 {up}(411.774,127.37) .. tension 6.32194 and 0.766362 ..
 {right}(449.841,195.363) .. tension 1.56573 and 1 ..
(476.389,172.917) .. tension 1 and 1.22255 ..
liii1 ( (506.617,125.999), (8.7213,-0.969033), (0,0) ) .. tension 1 and 2.84124 ..
liii1 ( (528.79,104.945), (27.9082,-6.78324), (-17.5712,-24.0202) ) setranchor
(621.398,-1.67052) rightjoinii
liii1 ( (530.058,2.56782), (2.31684,-0.434351), (-6.49804,-0.87773) ) .. tension 3.90213 and 1 ..
 {left}liii1 ( (528.675,2.96036), (0,0), (0,0) ) .. tension 1.13482 and 1.15751 ..
 {down}(525.869,-1.73479) .. tension 1.13331 and 0.956441 ..
(504.481,-97.4376) .. tension 0.985502 and 1.18217 ..
 {left} cycle
;

%%endpaths
%%beginbody



enddefchar;
beginchar(heh.fina.allah,-1,-1,-1,-1);
%%beginbody

allah_(0,0);

cutGlyph(z1,z4,false);

i_ := 0;
path p;
for item within allah.pic:
i_ := i_ + 1;
p := pathpart item;
exitif i_ = 2;
endfor

fill p;


tr_ := identity shifted ( xpart lrcorner currentpicture - x1,0);

endchar;
beginchar(lam.medi.allah,-1,-1,-1,-1);
%%beginbody


allah_(0,0);

cutGlyph(z2,z3,false);
cutGlyph(z1,z4,true);
leftbearing := 0;

tr_ := identity shifted( -x1,0);

charwd := x2 - x1;
endchar;
beginchar(lam.init.allah,-1,-1,-1,-1);
%%beginbody

allah_(0,0);

cutGlyph(z2,z3,true);
leftbearing := 0;

tr_ := identity shifted ( xpart llcorner currentpicture - x2,0);


endchar;
beginchar(hamza.isol,1569,-1,-1,-1);
%%backgroundimage:images/hamza.isol.jpg,-1023.13,-1080.52,1,0,0,1

%%beginpaths

fill
(61.7679,71.7568) .. tension 1.53875 and 1.8757 ..
 {right}(208.979,215.832) .. tension 1 and 1.57465 ..
 {down}(265.196,160.922) .. tension 2.86515 and 1.56875 ..
 {left}(222.15,114.642) .. tension 1.55216 and 2.09024 ..
 {left}(165.985,142.86) .. tension 1.07159 and 7.34378 ..
 {down}(145.05,123.735) .. tension 2.31243 and 2.40414 ..
 {right}(223.634,86.8183) .. tension 1.16475 and 1.03238 ..
 {right}(335.866,110.197) .. tension 1 and 1 ..
 {down}(354.442,89.3629) .. tension 2.13549 and 2.56704 ..
(320.833,46.4065) .. tension 2.43205 and 1 ..
(269.696,36.158) .. tension 1 and 11.0243 ..
 {left}(125.071,-25.4181) .. tension 0.75 and 1 ..
 {up}(108.219,-10.9028) .. tension 0.75 and 4.82517 ..
 {up}(120.048,17.1049) .. tension 12.9605 and 1.50368 ..
 {up} cycle
;

%%endpaths
%%beginbody

%currentpicture := currentpicture shifted (0,-ypart llcorner currentpicture);

endchar;
defchar(alef.isol,1575,-1,-1,-1);
%%backgroundimage:images/alef.isol.jpg,-1.91071,-1117.34,1,0,0,1

%%beginverbatim
%lefttatweel := lefttatweel - 1;

y33 := 20 *nuqta;

%%endverbatim

%%beginpaths

fill
(163.724,-0.694444) {left} .. tension 0.777756 and 1 ..
 {up}(142.732,25.6944) .. tension 1 and 1.22126 ..
 {up}(143.03,59.4726) --
(135.636,170.553) --
leii0 ( (94.7371,518.345), (-310.542,y33) ) .. tension 1.41886 ..
 {up}leii0 ( (91.578,557.96), (-310.542,y33) ) .. tension 3.38094 and 1.27776 ..
 {right}leii0 ( (133.635,642.798), (-310.542,y33) ) .. tension 0.75 and 2.79505 ..
leii0 ( (152.664,619.736), (-310.542,y33) ) --
(200.696,204.57) .. tension 1 ..
(204.981,149.228) {down} .. tension 1.00275 and 2.69468 ..
 {left} cycle
;

%%endpaths
%%beginbody
leftbearing := leftbearing + 0;

enddefchar;
defchar(alef.isol.ii,-1,-1,-1,-1);
%%beginbody

alef.isol_(-0.5,0);
enddefchar;
defchar(alef.fina,-1,-1,-1,-1);
%%backgroundimage:images/alef.fina.jpg,-560.917,-1136.39,1,0,0,1
%%beginparams
rightVerticalRatio := 5;

%%beginverbatim

save _tatweel; numeric _tatweel;
_tatweel := 20 * nuqta;

%%endverbatim

%%beginpaths

fill
leii0 ( (91.9722,613.556), (-211.408,_tatweel) ) .. tension 1.29322 and 2.09511 ..
 {right}leii0 ( (128.5,669.806), (-211.408,_tatweel) ) .. tension 1.2503 and 2.76737 ..
leii0 ( (160.648,616.491), (-211.408,_tatweel) ) ..
leii0 ( (174,517), (-211.408,_tatweel) ) --
(200.157,156.315) .. tension 1 and 1 ..
liii1 ( (235.583,107.278), (1.44676,-10.6096), (-32.2319,-15.7969) ) setranchor
(271,-1) rightjoinii
liii1 ( (186.028,26), (29.4174,-13.9853), (0.279082,-36.8388) ) .. tension atleast 1 ..
liii1 ( (158.139,58.6944), (0,0), (9.48878,-28.1872) ) ..
(139,121) --
leii0 ( (114.032,493.449), (-211.408,_tatweel) ) .. tension 1 and 1 ..
leii0 ( (103,569), (-211.408,_tatweel) ) .. tension 1 and 14.433 ..
 {up} cycle
;

%%endpaths
%%beginbody

enddefchar;
defchar(alef.fina.afterkaf,-1,-1,-1,-1);
%%beginbody
alef.fina_(lefttatweel,righttatweel+0.3);
enddefchar;
defchar(lam.medi.laf,-1,-1,-1,-1);
%%backgroundimage:images/lam.alef.fina.jpg,-2615.79,-1061.89,1,0,0,1
%%beginparams
rightVerticalRatio := 5;
z.mark = (628,187);

%%beginverbatim



%%endverbatim

%%beginpaths

fill
(318.464,-38.7518) {up} .. tension atleast 0.980748 ..
(347.913,-15.1582) .. tension 20.0142 and 1 ..
(565.917,71.7593) .. tension 1.16279 and 1.73871 ..
 {up}(688.103,363.522) .. tension 1.5751 and 0.75 ..
 {up}(686.837,492.54) .. tension 0.94098 and 2.75568 ..
 {right}(723.799,649.403) .. tension 2.11993 and 1 ..
(747.146,593.056) .. tension 1 and 1 ..
(756.889,472.222) .. tension 1 and 9.28107 ..
(800.028,165.098) ..
liii1 ( (856.959,102.773), (155.768,-131.173), (-73.3025,1.44676) ) setranchor
(882.098,0.482253) rightjoinii
liii1 ( (850.63,1.19341), (213.638,-158.179), (-76.196,-0.964508) ) ..
liii1 ( (779.644,34.5564), (6.26929,-14.9498), (-3.37577,-4.82253) ) ..
(753.844,75.0065) ..
(728.936,226.542) .. tension 1 and 4.3304 ..
 {left}(723.459,247.792) .. tension 1.12905 and 1 ..
(718.024,240.253) .. tension 0.826673 and 1.09605 ..
(551.997,-17.6784) .. tension 1.09781 and 2.66853 ..
 {left}(332.256,-57.5569) .. tension atleast 1 ..
 cycle
;

%%endpaths
%%beginbody


leftbearing := -300;

%labels(1,mark);
setCursiveAnchor(ltrcursive,z.mark, ExitAnchor);

enddefchar;
defchar(lam.medi.laf.afterkaf,-1,-1,-1,-1);
%%beginbody

lam.medi.laf_(lefttatweel,righttatweel+0.2);


enddefchar;
defchar(alef.fina.laf,-1,-1,-1,-1);
%%backgroundimage:images/lam.alef.fina.jpg,-2688.41,-1063.8,1,0,0,1
%%beginparams
z11 = (551.888,185.693);

%%beginverbatim

%%endverbatim

%%beginpaths

fill
(309.567,449.801) {left} .. tension 3.27976 and 1 ..
 {left}(290.71,435.85) .. tension 1 and 2.26506 ..
(226.276,454.857) ..
 {up}(182.306,563.288) .. tension 3.38468 and 1.01066 ..
 {right}(201.707,600.434) .. tension 1.14974 and 1 ..
(305.354,560.659) .. tension 1.04396 and 1.33341 ..
(437.343,466.31) .. tension 1 and 1 ..
(540.393,334.408) .. tension 1 and 0.931615 ..
 {down}(572.697,226.98) .. tension 1.1497 and 1.41495 ..
 {left}z11 .. tension 0.957142 and 1.44203 ..
(536.948,202.465) .. tension 6.24245 and 0.861182 ..
(420.953,376.44) .. tension 1.73238 and 2.78471 ..
 cycle
;

%%endpaths
%%beginbody



setCursiveAnchor(ltrcursive,z11, EntryAnchor);

enddefchar;
beginchar(lam.init.lamalef,-1,-1,-1,-1);
%%beginbody

lamalef.isol_(lefttatweel,righttatweel);

cutGlyph(z1,z2,false);

setCursiveAnchor(ltrcursive,z1, ExitAnchor);

leftbearing := 0;

endchar;
beginchar(alef.fina.lamalef,-1,-1,-1,-1);
%%beginbody

lamalef.isol_(lefttatweel,righttatweel);

cutGlyph(z1,z2,true);

setCursiveAnchor(ltrcursive,z1, EntryAnchor);


rightbearing := -250;

endchar;
defchar(behshape.isol,-1,-1,-1,-1);
%%backgroundimage:images/beh.isol.jpg,-40.8598,-987.44,1,0,0,1

%%beginverbatim
%lefttatweel := lefttatweel - 1;

minA0 := -2;
maxA0 := 2;

x33 := - minA0 *nuqta;
x34 := - maxA0 *nuqta;

%%endverbatim

%%beginpaths

fill
liii0 ( (10.7138,119.804), (x34,0), (x33,0) ) .. tension 1.47376 and 2.37253 ..
 {right}liii0 ( (76.2594,239.73), (x34,0), (x33,0) ) .. tension 0.75 and 2.19563 ..
 {down}liii0 ( (87.915,218.42), (x34,0), (x33,0) ) .. tension 2.87221 and 0.75 ..
 {down}liii0 ( (76.5194,162.938), (x34,0), (x33,0) ) ..
liii0 ( (96.714,123), (x34,0), (x33,0) ) .. tension 1 and 1.21559 ..
 {right}liii0 ( (255.069,78.9174), (-164.4,-18), (196.8,24) ) .. tension 1 and 7.36562 ..
 {up}(606.631,141.141) .. tension 1.46476 and 7.70909 ..
 {up}(548.693,238.217) .. tension 1.41144 and 17.3247 ..
 {right}(583.825,314.289) .. tension 5.16974 and 0.867889 ..
 {down}(673.075,168.598) .. tension 2.54178 and 0.849674 ..
(660.826,114.668) .. tension 1 and 1 ..
(516.714,18) .. tension 1 and 1 ..
 {left}liii0 ( (234.992,-15.325), (-164.4,-18), (196.8,24) ) .. tension 1 and 1 ..
liii0 ( (33.314,59.84), (x34,0), (x33,-6) ) ..
 {up} cycle
;

%%endpaths
%%beginbody

enddefchar;
defchar(behshape.init,-1,-1,-1,-1);
%%backgroundimage:images/behshape.init.jpg,-1974,-1222.83,1,0,0,1
%%beginparams
leftVerticalRatio := 10;
z1 = bldmv ( (41,455), (-17.3083,-9.28014), (-17.3199,-18.0564) );

%%beginverbatim


%%endverbatim

%%beginpaths

fill
bldmv ( (67,4), (-17.3083,-9.28014), (9.48895,-7.60459) ) leftjoin
bldmv ( (82.4184,102.837), (-4.19024,-4.48763), (10.4889,-7.25595) ) .. tension 0.96304 and 1.10972 ..
 {up}(92.6743,118.302) .. tension 0.850657 and 1.78806 ..
 {up}(50,189) .. tension 1 and 3.33785 ..
 {right}(84,266) .. tension 3.03159 and 1 ..
 {down}(155,132) .. tension 0.870917 and 1 ..
(135,47) .. tension 1 and 1 ..
 cycle
;

%%endpaths
enddefchar;
defchar(behshape.init.beforereh,-1,-1,-1,-1);
%%backgroundimage:images/beh.init.jpg,-1372.65,-1299.44,1,0,0,1
%%beginbody


behshape.init_(-0.2,0);


enddefchar;
defchar(behshape.init.beforebeh,-1,-1,-1,-1);
%%beginbody


behbeh_(lefttatweel,righttatweel);

cutGlyph(z1,z2,true);

leftanchor := z2;


enddefchar;
defchar(behshape.init.beforeyeh,-1,-1,-1,-1);
%%backgroundimage:images/behyeh.jpg,-2986.77,-1042.62,1,0,0,1
%%beginparams
z1 = (-0.403764,88.1158);

%%beginpaths

fill
(58.1958,385.452) .. tension 1.04084 and 2.91058 ..
 {right}(93.9021,454.124) .. tension 17.7179 and 0.897121 ..
 {down}(192.224,281.079) .. tension 1.09638 and 0.75 ..
 {left}z1 .. tension 1.58338 and 5.07289 ..
(23.8951,149.921) .. tension 4.64593 and 2.78952 ..
 {up}(141.919,221.799) .. tension 1.84368 and 8.51774 ..
 {up} cycle
;

%%endpaths
%%beginbody
leftbearing:=0;
rightbearing := 50;
setCursiveAnchor(ltrcursive,z1,ExitAnchor);
enddefchar;
defchar(behshape.init.beforeseen,-1,-1,-1,-1);
%%backgroundimage:images/behbeforeseen.jpg,-1057.82,-1108.29,1,0,0,1
%%beginparams
leftVerticalRatio := 6;
z1 = (58.5196,25.9416);

%%beginverbatim


lefttatweel := lefttatweel - 0.5;


%%endverbatim

%%beginpaths

fill
z1 ..
(-21.0544,-1.33146) link
(35.4349,103.178) .. tension 1 and 1 ..
 {up}(41.7206,110.466) .. tension 1.4166 and 1 ..
(26.4632,146.872) .. tension 1 and 1.46208 ..
(-25.7724,215.012) .. tension 1 and 1.08205 ..
 {up}(-53.0141,253.079) .. tension 0.91899 and 1.34948 ..
 {right}(-23.7299,334.518) .. tension 3.73236 and 1.70708 ..
(98.3142,127.391) {down} .. tension 0.75 and 1.59291 ..
 cycle
;

%%endpaths
%%beginbody


enddefchar;
defchar(behshape.init.beforenoon,-1,-1,-1,-1);
%%backgroundimage:images/behbeforenoon.jpg,-2684.14,-1070.53,1,0,0,1
%%beginparams
leftVerticalRatio := 10;

%%beginverbatim

lefttatweel := lefttatweel - 0.1;

pair _temp;
_temp := joinvector;
joinvector := (0,lineheight);
%%endverbatim

%%beginpaths

fill
(165.063,37.2969) ..
bldmv ( (126.89,17.0683), (7.23381,2.41127), (6.31813,-2.67885) ) leftjoin
bldmv ( (122.715,104.502), (3.238,-3.9915), (14.9823,7.46694) ) .. tension 1 and 2.14514 ..
 {up}(141.685,127.369) .. tension 1 and 1.78806 ..
 {up}(118.183,176.745) .. tension 1 and 3.33785 ..
 {right}(143.794,254.816) .. tension 3.03159 and 1 ..
 {down}(196.22,134.859) .. tension 1 and 1.14234 ..
(182.745,64.8926) .. tension 1 and 1 ..
 cycle
;

%%endpaths
%%beginbody

joinvector := _temp;

setCursiveAnchor(rtlcursive,leftanchor, ExitAnchorRTL);
%showAnchors := 1;
enddefchar;
defchar(behshape.init.beforehah,-1,-1,-1,-1);
%%backgroundimage:images/behhah.jpg,-1743,-1059,1,0,0,1
%%beginparams
behshape.init.beforehah.dir1 := 34;
z1 = (70,263);

%%beginpaths

fill
(120.198,187.182) --
z1 {dir behshape.init.beforehah.dir1} .. tension 1.63667 and 1 ..
(207.389,332.521) .. tension 0.75 and 2.43732 ..
 {right}(417.63,527.681) .. tension 1.66956 and 1.37271 ..
 {down}(506.365,402.585) .. tension 1 and 2.36968 ..
 {left}(472.292,317.357) .. tension 1.23297 and 1.55771 ..
(450.827,354.323) .. tension 1.47542 and 2.46085 ..
 {left}(391.396,427.179) .. tension 4.4689 and 1 ..
(282.407,306.713) .. tension 1.31313 and 10.2151 ..
 {left} cycle
;

%%endpaths
%%beginbody


leftbearing:=-200;
rightbearing := 120;

setCursiveAnchor(rtlcursive,z1, ExitAnchorRTL);

enddefchar;
defchar(behshape.medi,-1,-1,-1,-1);
%%backgroundimage:images/behmedi3.jpg,-1007.19,-1028.46,1,0,0,1

%%beginpaths

fillc
bldmv ( (227,162), (8,22), (0,0) ) {right} .. tension 1.79471 and 1 ..
brdmv ( (261,141), (-3.6212,2.99202), (-18.7783,0.242692) ) setranchor
(379,0) rightjoinii
bldmv ( (199,68), (13,1), (0,0) ) leftjoin
bldmv ( (158,114), (-46,-6), (14.5278,-4.31711) ) ..
bldmv ( (196,147), (28,24), (0,0) ) .. tension 1 and 1 ..
 cycle
;

%%endpaths
%%beginbody

%z.rt.rbearing = (332.902,0.659722);
show leftanchor;
show rightanchor;
enddefchar;
defchar(behshape.medi.afterbeh,-1,-1,-1,-1);
%%beginbody


behbeh_(lefttatweel,righttatweel);

cutGlyph(z1,z2,false);

rightanchor := z2;
enddefchar;
defchar(behshape.medi.expa,-1,-1,-1,-1);
%%backgroundimage:images/behmediexpa.jpg,-2094.73,-1126.75,1,0,0,1
%%beginparams
z.mark1 = (156.203,403.222);

%%beginverbatim

%%endverbatim

%%beginpaths

fill
(172,34) leftjoin
bldmv ( (149,118), (-36.016,-17.2757), (0,-24) ) .. tension 0.932615 and 1.60814 ..
bldmv ( (165,135), (-19,-18), (1,-10) ) .. tension 1 and 1.18468 ..
bldmv ( (181,158), (17,27), (3,1) ) .. tension 1 and 0.862104 ..
 {right}bldmvi ( (211,180), (8,10) ) .. tension 0.75 and 1.72888 ..
bldmvi ( (232,146), (5,10) ) .. tension 5.00355 and 3.4906 ..
brdmvi ( (219,114), (0,0) ) .. tension 0.856594 and 1 ..
brdmv ( (221,103), (0,0), (-3,-7) ) setranchor
brdmv ( (346,0), (-1.68009,1.4977), (-2.43527,0.644556) ) rightjoinii
brdmv ( (175,34), (0,0), (0,0) ) ..
 {left}(173,35) .. tension 5.0706 and 1 ..
 cycle
;

%%endpaths
%%beginbody
%labels(1,2,3,4);




x.mark1 := x.mark1 - lefttatweel * nuqta * 0.1;

defAnchor(onedotup,z.mark1,MarkAnchor);
defAnchor(topmark,z.mark1 - (800,0),MarkAnchor);

enddefchar;
defchar(behshape.medi.expa.ii,-1,-1,-1,-1);
%%backgroundimage:images/sad.init.jpg,-1799.43,-1018.94,1,0,0,1
%%beginparams
z.onedotup = (156.203,403.222);

%%beginverbatim

%%endverbatim

%%beginpaths

fill
bldmv ( (134,120), (-11,16), (10,1) ) .. tension 1 and 1.18468 ..
bldmvi ( (150,153), (0,5) ) .. tension 1 and 1.33378 ..
 {right}bldmvi ( (173,203), (4.59276,8.83971) ) .. tension 1.18515 and 1.72888 ..
 {down}bldmvi ( (193,178), (2.33089,9.88619) ) .. tension 5.00355 and 3.4906 ..
brdmvi ( (195,154), (3,1) ) .. tension 0.856594 and 1 ..
brdmv ( (239,101), (33,17), (-18,-5) ) setranchor
brdmv ( (349.27,-1.46295), (-1.68009,1.4977), (-2.43527,0.644556) ) rightjoinii
(174,63) leftjoin
bldmv ( (108,99), (-143,-14), (30,-7) ) .. tension 0.932615 and 1.60814 ..
 cycle
;

%%endpaths
%%beginbody

z.topmark = z.onedotup - (200,0);



%x.mark1 := x.mark1 - lefttatweel * nuqta * 0.1;

setMarkAnchor(onedotup,z.onedotup);
setMarkAnchor(topmark,z.topmark);

enddefchar;
defchar(behshape.medi.beforeseen,-1,-1,-1,-1);
%%backgroundimage:images/beh.medi.between.jpg,-1921.75,-1075.83,1,0,0,1
%%beginparams
leftVerticalRatio := 10;
rightVerticalRatio := 10;

%%beginverbatim

%righttatweel := righttatweel; % - 0.3;
%lefttatweel := lefttatweel;% - 0.3;



%%endverbatim

%%beginpaths

fill
(115.456,294.033) .. tension 1 and 2.56646 ..
liii1 ( (182.996,122.802), (0,0), (0,0) ) setranchor
liii1 ( (226,0), (23.1638,-4.18622), (3.16292,-26.6058) ) rightjoinii
liii0 ( (123.135,53.9895), (-0.279082,-19.2566), (0,0) ) {curl1} ..
liii0 ( (112.934,52.3824), (-2.27917,-19.1171), (-11.0702,-26.1406) ) leftjoin
liii0 ( (81.1923,111.554), (0,0), (4.18627,-3.72109) ) .. tension 1 and 1.70271 ..
 {up}(91.4108,130.864) .. tension 1.7264 and 1 ..
 {up}(50.7419,273.204) .. tension 1 and 1.08728 ..
 {right}(82.3349,349.81) .. tension 1.98947 and 1 ..
 cycle
;

%%endpaths
%%beginbody
%labels(1,2,3,4);


enddefchar;
defchar(behshape.medi.beforereh,-1,-1,-1,-1);
%%backgroundimage:images/beh_rah.jpg,-507.682,-871.324,1,0,0,1
%%beginparams
leftVerticalRatio := 12;
leftVerticalRatioNeg := 40;

%%beginverbatim


save ljoinvector;pair ljoinvector;ljoinvector := (0,lineheight);


%%endverbatim

%%beginpaths

fill
bldmv ( (77,170), (-10,-1), (7.2338,-1.60751) ) .. tension 2.5981 and 1.53504 ..
 {right}(116,236) .. tension 2.13086 and 1 ..
(158,142) .. tension 1 and 1 ..
brdmv ( (171,86), (51.9092,-60.2816), (0,0) ) .. tension 1 and 1 ..
brdmv ( (243,-50), (409.954,-109.423), (-38.1944,11.5741) ) setranchor
brdmv ( (333,-162), (0,0), (0,0) ) rightjoinii
brdmv ( (225,-148), (314.4,-87.6), (-70.0606,34.6954) ) .. tension 1 and 1 ..
(117,41) .. tension 1 and 1.01253 ..
 {curl1}(107,106) ..
bldmv ( (79,48), (-248,-40), (29,-5) ) leftjoin
bldmv ( (67,136), (-250,-57), (8,-10) ) .. tension 1 and 3.59506 ..
 cycle
;

%%endpaths
%%beginbody



setCursiveAnchor(rtlcursive,leftanchor+ljoinvector, ExitAnchorRTL);

tr_ := tr_ shifted (0,162);

z.mark2 = leftanchor;

pair leftanchor;

%show anchors[anchors.rtlcursive].anctype ;

enddefchar;
defchar(behshape.medi.beforenoon,-1,-1,-1,-1);
%%beginbody


behshape.medi.beforereh_(lefttatweel,righttatweel);
setCursiveAnchor(rtlcursive,z.mark2 + (10,0), ExitAnchorRTL);






enddefchar;
defchar(behshape.medi.beforeyeh,-1,-1,-1,-1);
%%backgroundimage:images/seenyeh.jpg,-506,-1005,1,0,0,1
%%beginparams
z1 = (454,-126);

%%beginverbatim

z3 = z1 + (76,83);

%(497.525,1.20559)
%%endverbatim

%%beginpaths

fill
(421.674,74.0053) .. tension 1 and 1.48115 ..
 {right}(547,171) .. tension 1.92066 and 1 ..
brdmv ( (605.387,131.589), (23.1481,8.68056), (-37.676,-7.20961) ) rightjoin
brdmv ( (506.463,80.6085), (0,0), (0,0) ) .. tension 1 and 3.4122 ..
 {left}(505.2,81.1775) .. tension 3.1021 and 1.93218 ..
 {down}(428.081,-1.1011) .. tension 1.65825 and 2.24052 ..
 {right}z3 .. tension 0.75 and 2.48039 ..
 {left}z1 .. tension 1.67416 and 1.31039 ..
 {up}(366.202,-59.1869) .. tension 1 and 1 ..
 cycle
;

%%endpaths
%%beginbody




leftbearing := 0;


setCursiveAnchor(ltrcursive,z1,ExitAnchor);


enddefchar;
defchar(behshape.fina,-1,-1,-1,-1);
%%backgroundimage:images/beh.fina.jpg,47.0425,-1195.96,1,0,0,1

%%beginverbatim

minA0 := -2;
maxA0 := 2;

x33 := - minA0 *nuqta;
x34 := - maxA0 *nuqta;


%%endverbatim

%%beginpaths

fill
liii0 ( (48.9701,132.538), (x34,0), (x33,0) ) .. tension 1.27714 and 1.53631 ..
 {right}liii0 ( (134.31,264.378), (x34,0), (x33,0) ) .. tension 0.971742 and 1.1457 ..
 {down}liii0 ( (151.802,239.75), (x34,0), (x33,0) ) .. tension 1.31378 and 0.75 ..
 {down}liii0 ( (122.995,169.996), (x34,0), (x33,0) ) .. tension 1.83538 and 1 ..
liii0 ( (127.313,149.411), (x34,0), (x33,0) ) .. tension 1.9942 and 0.823294 ..
 {right}liii0 ( liii0 ( (352.71,58.1988), (0,0), (0,0) ), (-181,-38), (167,42) ) .. tension 1 and 2.05571 ..
liii0 ( (646.942,130.981), (-5,1), (0,0) ) .. tension 1.46476 and 1 ..
(667.056,168.056) .. tension 1 and 0.977921 ..
 {right}(715.453,198.913) .. tension 1.03362 and 1.43805 ..
 {down}(728.295,178.074) .. tension bldmvi ( 1.39725, 0 ) and 1 ..
 {down}(718.813,139.08) .. tension 1 and 1 ..
liii1 ( (727.819,114.133), (2.34429,1.67449), (0,0) ) .. tension 1 and 1 ..
liii1 ( (745.453,102.946), (14.4006,-2.67918), (-13.3959,-18.4194) ) setranchor
(758.468,-0.803755) rightjoinii
liii1 ( (734.922,3.55362), (65.9749,2.34429), (-44.2065,-16.7449) ) .. tension 1 and 1 ..
liii1 ( (681.475,64.9113), (-1.67449,3.68388), (0,0) ) .. tension 1 and 1 ..
 {left}(675.97,70.8131) .. tension 14.6137 and 1 ..
liii0 ( (640.853,42.0353), (-7,-4), (0,0) ) .. tension 1.73736 and 0.75 ..
 {left}liii0 ( liii0 ( (317.834,-34.2764), (0,0), (0,0) ), (-181,-38), (167,42) ) .. tension 0.892193 and 1.23953 ..
liii0 ( (57.1411,93.4344), (x34,0), (x33,0) ) .. tension 1 and 1.20242 ..
 {up} cycle
;

%%endpaths
%%beginbody

enddefchar;
defchar(seen.sinna.beforereh,-1,-1,-1,-1);
%%backgroundimage:images/seeninitreh.jpg,-1045.89,-977.361,1,0,0,1
%%beginparams
rightVerticalRatio := 10;
rightVerticalRatioNeg := 18;
z.seenreh = (-68.5013,54.2412);

%%beginverbatim


%%endverbatim

%%beginpaths

fill
(-26.0752,33.274) .. tension 2.43844 and 2.31353 ..
 {up}z.seenreh .. tension 0.759215 and 2.22631 ..
(-33.1003,108.507) .. tension 22.4214 and 22.4214 ..
 {right}(196.118,161.901) .. tension 0.75 and 5.74099 ..
 {down}(205.381,149.017) .. tension 1 and 1 ..
(208.508,111.401) .. tension 1 and 1 ..
brdmv ( (227.021,100.998), (0,0), (-8.23678,-0.646022) ) rightjoin
(137.624,62.5328) {left} .. tension 4.18621 and 1 ..
 {left} cycle
;

%%endpaths
%%beginbody
leftbearing := 0;
enddefchar;
defchar(seen.twosinnas,-1,-1,-1,-1);
%%backgroundimage:images/seenyeh.jpg,-1145.81,-1014.75,1,0,0,1

%%beginverbatim


%%endverbatim

%%beginpaths

fill
(229.419,222.36) .. tension 1 and 1 ..
 {down}(248.194,197.75) .. tension 1 and 1 ..
 {down}(235.194,143.75) .. tension 1.8664 and 4.74066 ..
 {right}(320.208,115.443) .. tension 1 and 1 ..
 {up}(340.194,122.75) .. tension 1 and 1 ..
 {up}(319.194,192.75) .. tension 1 and 7.19664 ..
 {right}(359.288,266.302) .. tension 2.05765 and 1 ..
 {down}(392.464,147.898) .. tension 1 and 2.91603 ..
 {left}(333.442,15.4452) .. tension 1 and 5.18399 ..
 {left}(189.017,54.2677) leftjoin
bldmv ( (152.901,105.903), (0,0), (3.39162,0) ) .. tension 1 and 1 ..
(163.378,115.392) .. tension 3.26881 and 1.41751 ..
 {right} cycle
;

%%endpaths
%%beginbody


enddefchar;
beginchar(seen.isol,1587,-1,-1,-1);
%%backgroundimage:images/seen.isol.jpg,46.7006,-1017.74,1,0,0,1

%%beginpaths

fill
(81.9721,13.3539) .. tension 0.904492 and 8.4763 ..
 {right}(166.496,191.788) .. tension 0.75 and 1.92446 ..
 {down}(176.972,179.583) .. tension 3.50408 and 1.02765 ..
 {down}(143.217,52.4262) .. tension 1.07129 and 0.939778 ..
 {right}(301.131,-56.7051) .. tension 1 and 2.02046 ..
 {up}(525.344,36.8423) .. tension 1.67752 and 1 ..
(508.253,115.305) .. tension 0.75 and 4.17877 ..
 {up}(461.288,203.892) .. tension 1 and 1.91269 ..
 {right}(496.525,282.185) .. tension 4.06396 and 1 ..
(545.721,214.892) .. tension 1 and 1 ..
 {right}(600.383,194.52) .. tension 1 and 0.893335 ..
(691.833,249.298) .. tension 1 and 1.46586 ..
 {right}(735.015,326.384) .. tension 1.31024 and 1 ..
(753.152,301.072) .. tension 3.05237 and 2.90237 ..
 {down}(744.565,254.601) .. tension 2.23839 and 1.70605 ..
(780.659,222.356) .. tension 1 and 2.32204 ..
 {up}(834.476,227.029) .. tension 2.94078 and 1 ..
 {up}(818.077,289.098) .. tension 3.66057 and 1.80853 ..
 {right}(852.332,359.6) .. tension 2.50477 and 1 ..
 {down}(888.248,234.236) .. tension 1.56 and 1.56684 ..
 {left}(820.313,122.76) .. tension 0.75 and 10.3975 ..
 {left}(712.351,156.962) .. tension 14.3471 and 0.75 ..
(645.491,114.381) .. tension 1.75101 and 0.983575 ..
 {left}(573.743,103.021) {dir -88.19} .. tension 1.08104 and 1.1434 ..
(550.565,-28.9417) .. tension 1.09281 and 1.17457 ..
 {left}(271.925,-149.153) .. tension 0.919648 and 1.14905 ..
 {up} cycle
;

%%endpaths
%%beginbody
savepicture:=1;
endchar;
defchar(seen.init,-1,-1,-1,-1);
%%backgroundimage:images/seen.init.jpg,-995.808,-1004.18,1,0,0,1
%%beginparams
leftVerticalRatio := 10;

%%beginverbatim



%lefttatweel := lefttatweel - 0.5;


%%endverbatim

%%beginpaths

fill
(133.965,154.765) .. tension 1 and 1.50971 ..
 {right}(177.917,199.333) .. tension 1.0342 and 0.957132 ..
 {down}(196,185.056) .. tension 1 and 1 ..
 {down}(181.833,120.417) .. tension 2.55542 and 1 ..
 {right}(225.367,106.78) .. tension 1 and 1.74241 ..
(291.508,124.437) .. tension 2.7341 and 1.20851 ..
 {right}(354.139,241.972) .. tension 1.31024 and 1 ..
 {down}(374,224.167) .. tension 2.29611 and 0.75 ..
 {down}(361.068,163.664) .. tension 2.23839 and 1.70605 ..
 {right}(422.02,138.397) .. tension 1 and 0.864209 ..
 {up}(437.778,150.333) .. tension 2.94078 and 1 ..
 {up}(427.157,189.921) .. tension 3.66057 and 1.10996 ..
 {right}(466.028,272.722) .. tension 1.26511 and 1 ..
 {down}(498.083,217.861) .. tension 1.56 and 1.11789 ..
 {left}(419.639,45.1389) .. tension 0.75 and 2.52485 ..
 {left}(318.972,69.0556) .. tension 3.90611 and 0.75 ..
 {left}(220.222,19.7222) .. tension 0.75 and 2.94203 ..
 {left}(146.306,53.7222) .. tension 3.29783 and 0.75 ..
bldmv ( (129.031,43.2508), (0,0), (8.68056,-8.68056) ) leftjoin
bldmv ( (102.213,111.367), (-37.7765,-9.64506), (35.0437,20.0135) ) .. tension 0.919648 and 1.14905 ..
 cycle
;

%%endpaths
%%beginbody

enddefchar;
defchar(seen.init.beforeyeh,-1,-1,-1,-1);
%%backgroundimage:images/seenyeh.jpg,-1139,-1018,1,0,0,1
%%beginbody


seen.twosinnas_(-0.5,0);

picture pic_;pic_ := image(behshape.medi.beforeyeh_(0,-0.2));
draw pic_ shifted (leftanchor-rightanchor);

setCursiveAnchor(ltrcursive,z1  shifted (leftanchor-rightanchor),ExitAnchor);

pair leftanchor, rightanchor;



enddefchar;
defchar(seen.init.beforereh,-1,-1,-1,-1);
%%backgroundimage:images/seeninitreh.jpg,-1233,-983,1,0,0,1
%%beginbody


seen.twosinnas_(-0.5,0);

picture pic_;pic_ := image(seen.sinna.beforereh_(0,-0.8));
draw pic_ shifted (leftanchor-rightanchor);

setCursiveAnchor(rtlcursive,z.seenreh  shifted (leftanchor-rightanchor),ExitAnchorRTL);

pair leftanchor, rightanchor;

enddefchar;
defchar(seen.medi,-1,-1,-1,-1);
%%backgroundimage:images/seen.medi.jpg,-1009.12,-1169.72,1,0,0,1
%%beginparams
leftVerticalRatio := 10;
rightVerticalRatio := 10;
z.mark1 = (57,254);

%%beginverbatim


%righttatweel := righttatweel - 0.5;
%lefttatweel := lefttatweel - 0.5;

%%endverbatim

%%beginpaths

fill
(104.859,111.75) .. tension 1 and 0.924762 ..
 {right}(145.499,156.895) .. tension 1 and 1 ..
 {down}(158.611,141.778) .. tension 0.75 and 1.74398 ..
 {down}(150.713,112.113) .. tension 0.830106 and 0.75 ..
 {right}(170.569,88.7858) .. tension 1.08033 and 1.08543 ..
(226.194,99.361) .. tension 1 and 0.983952 ..
 {right}(303,172) .. tension 1 and 1 ..
 {down}(314.833,152.083) .. tension 1 and 2.64995 ..
 {down}(305.854,122.556) .. tension 0.75 and 0.75 ..
 {right}(331.417,99.694) .. tension 1.0078 and 0.988916 ..
 {right}(424,191) .. tension 1 and 1 ..
 {down}(437.917,174.167) .. tension 1 and 1 ..
 {down}(430.083,135.806) .. tension 1 and 1.7669 ..
liii1 ( (453.042,102.861), (0,0), (-74.3474,-3.6169) ) setranchor
(462,-1) rightjoinii
(386.139,51.3333) {left} .. tension 12.1099 and 0.75 ..
 {left}(300.333,11.6944) .. tension 1.33775 and 1.26325 ..
 {left}(244.972,28.8611) .. tension 2.18145 and 1 ..
 {left}(143.833,-2.30556) .. tension 0.75 and 1 ..
 {left}(87.7478,10.9992) .. tension 1 and 4.68961 ..
 {left}liii0 ( (36.7808,2.66589), (-44.4444,-12.5), (79.5718,0.803755) ) leftjoin
liii0 ( (55.8534,99.1187), (-8.33333,-14.5833), (78.3661,2.81314) ) .. tension 1 and 1.69521 ..
 cycle
;

%%endpaths
%%beginbody

setMarkAnchor(smallhighwaw,z.mark1);
enddefchar;
defchar(seen.medi.afterbeh,-1,-1,-1,-1);
%%backgroundimage:images/behbeforeseen.jpg,-561.824,-1137.28,1,0,0,1
%%beginparams
leftVerticalRatio := 10;
rightVerticalRatio := 10;
z.mark1 = (87,277);

%%beginverbatim


%righttatweel := righttatweel - 0.5;
%lefttatweel := lefttatweel - 0.5;

%%endverbatim

%%beginpaths

fill
(109.199,122.36) .. tension 1 and 0.924762 ..
 {right}(145.499,156.895) .. tension 1 and 1 ..
 {down}(158.611,141.778) .. tension 0.75 and 1.74398 ..
 {down}(150.713,112.113) .. tension 0.830106 and 0.75 ..
 {right}(182.143,85.41) .. tension 1.08033 and 1.08543 ..
(242.108,101.29) .. tension 1 and 0.983952 ..
 {right}(301.553,170.553) .. tension 1 and 1 ..
 {down}(314.833,152.083) .. tension 1 and 2.64995 ..
 {down}(307.783,114.84) .. tension 1.36817 and 0.75 ..
 {right}(330.935,105.481) .. tension 1.0078 and 0.988916 ..
 {right}(412.908,182.319) .. tension 1 and 1 ..
 {down}(425.378,167.415) .. tension 1 and 1.7669 ..
liii1 ( (429.894,141.441), (0,0), (-74.3474,-3.6169) ) setranchor
(462,30) rightjoinii
(385.174,54.2268) {left} .. tension 12.1099 and 0.75 ..
 {left}(300.333,11.6944) .. tension 1.33775 and 1.26325 ..
 {left}(252.206,24.0386) .. tension 2.18145 and 1 ..
 {left}(187.718,1.07021) .. tension 0.75 and 1 ..
 {left}(106.556,29.3248) .. tension 1 and 4.68961 ..
 {left}liii0 ( (51.7306,8.93518), (-45.8912,-5.74846), (98.8619,26.3632) ) leftjoin
liii0 ( (55.8534,99.1187), (-12.6736,-5.90274), (78.3661,2.81314) ) .. tension 1 and 1.69521 ..
 cycle
;

%%endpaths
%%beginbody

setMarkAnchor(smallhighwaw,z.mark1);
enddefchar;
defchar(seen.twosinnas.medi,-1,-1,-1,-1);
%%backgroundimage:images/seem_medi_yeh_fina.jpg,-823.57,-782.567,1,0,0,1

%%beginverbatim

%lefttatweel := lefttatweel - 0.5;
%%endverbatim

%%beginpaths

fill
(233.628,176.148) {right} .. tension 1 and 1 ..
 {down}(249.027,153.95) .. tension 1 and 1 ..
 {down}(241.332,109.595) .. tension 1.8664 and 4.74066 ..
 {right}(274.262,100.578) .. tension 1 and 1 ..
(317.879,151.287) .. tension 1 and 0.905873 ..
 {right}(364.461,191.637) .. tension 2.05765 and 1 ..
 {down}brdmv ( (370.681,123.388), (0,0), (3.33333,-16.6667) ) rightjoin
brdmv ( (330.212,49.6011), (0,0), (0,0) ) {left} .. tension 10.8988 and 0.75 ..
(252.282,10.7445) {left} .. tension 0.75 and 5.18399 ..
 {left}bldmv ( (198.048,29.7576), (0,0), (0,0) ) leftjoin
bldmv ( (160.968,98.7543), (0,0), (0,0) ) .. tension 1 and 1 ..
(188.323,126.086) .. tension 3.26881 and 1.41751 ..
 cycle
;

%%endpaths
%%beginbody


enddefchar;
defchar(seen.medi.beforeyeh,-1,-1,-1,-1);
%%backgroundimage:images/seem_medi_yeh_fina.jpg,-823,-781,1,0,0,1
%%beginbody




seen.twosinnas.medi_(-0.5,righttatweel);

pair shift_;
picture pic_;

pic_ := image(
save rightanchor;pair rightanchor;clearxy;
behshape.medi.beforeyeh_(0,-0.3);
shift_ := leftanchor - rightanchor;
setCursiveAnchor(ltrcursive,z1  shifted shift_,ExitAnchor);
);

draw pic_ shifted shift_;


pair leftacnhor;

enddefchar;
defchar(seen.medi.beforereh,-1,-1,-1,-1);
%%backgroundimage:images/seen_medi_reh_fina.jpg,-1190,-1098,1,0,0,1
%%beginparams
z.mark1 = (57,254);
z1 = (-144,54);

%%beginverbatim


%righttatweel := righttatweel - 0.5;
%lefttatweel := lefttatweel - 0.5;

%%endverbatim

%%beginpaths

fill
(86.499,163.895) .. tension 1 and 1 ..
 {down}(109.611,140.778) .. tension 0.75 and 1.74398 ..
(108.713,115.113) .. tension 1.7809 and 0.75 ..
 {right}(173.569,90.7858) .. tension 1.08033 and 1.08543 ..
(222.194,101.361) .. tension 1 and 0.983952 ..
 {right}(297,170) .. tension 1 and 1 ..
 {down}(309.833,148.083) .. tension 1 and 2.64995 ..
 {down}(297.854,112.556) .. tension 1.02376 and 0.75 ..
 {right}(326.417,97.694) .. tension 1.0078 and 0.988916 ..
 {right}(426,198) .. tension 1 and 1 ..
 {down}(437.917,174.167) .. tension 1 and 1 ..
 {down}(430.083,135.806) .. tension 1 and 1.7669 ..
liii1 ( (453.042,102.861), (0,0), (-74.3474,-3.6169) ) setranchor
(462,0) rightjoinii
(386.139,51.3333) {left} .. tension 12.1099 and 0.75 ..
 {left}(294.333,0.6944) .. tension 1.33775 and 1.26325 ..
 {left}(230.972,10.8611) .. tension 2.18145 and 1 ..
 {left}(149.833,-8.3056) .. tension 0.75 and 1 ..
(71,17) .. tension 1 and 1.95831 ..
 {left}(8.7478,56.9992) .. tension 1 and 1 ..
 {left}(-106,30) .. tension 1 and 1 ..
 {up}z1 .. tension 1 and 1 ..
(-107,124) .. tension 1.62408 and 4.68961 ..
 cycle
;

%%endpaths
%%beginbody

setMarkAnchor(smallhighwaw,z.mark1);
setCursiveAnchor(rtcursii,z1, ExitAnchorRTL);
enddefchar;
defchar(seen.fina,-1,-1,-1,-1);
%%backgroundimage:images/seen.fina.jpg,-497,-1082,1,0,0,1
%%beginbody




seen.twosinnas.medi_(-0.7,righttatweel);

pair shift_;
picture pic_;

pic_ := image(
save rightanchor;pair rightanchor;clearxy;
noonshape.fina_(0,0);
shift_ := leftanchor - rightanchor;
%setCursiveAnchor(rtlcursive,z.seenreh shifted shift_, ExitAnchorRTL);
);

draw pic_ shifted shift_;


pair leftanchor;
%showAnchors := 1;


enddefchar;
beginchar(lam.isol,1604,-1,-1,-1);
%%backgroundimage:images/lam.isol.jpg,-22.6651,-945,1,0,0,1

%%beginpaths

fill
(57.7222,78.9167) .. tension 1 and 6.68185 ..
 {right}(132.141,230.715) .. tension 1 and 1 ..
 {down}(143.139,210.576) .. tension 0.987321 and 1 ..
 {down}(107.457,108.295) .. tension 0.947674 and 1.03981 ..
 {right}(245.917,2.5278) .. tension 0.791682 and 2.26577 ..
 {up}(441.384,85.8413) .. tension 3.77527 and 18.2673 ..
(398.019,308.642) .. tension 16.3689 and 16.3689 ..
(357.958,543.329) .. tension 2.62357 and 0.75 ..
 {up}(337.224,603.952) .. tension 1 and 2.05753 ..
 {right}(385.588,720.2) .. tension 1.56454 and 1 ..
(409.603,633.692) .. tension 0.937294 and 4.02183 ..
 {down}(462.627,612.629) .. tension 0.75 and 9.76203 ..
(420.403,526.539) {down} .. tension 1.12252 and 1.59686 ..
 {down}(484.806,121.972) .. tension 0.793905 and 1 ..
 {left}(232.62,-85.426) .. tension 0.812259 and 0.892519 ..
 {up} cycle
;

%%endpaths
endchar;
defchar(lam.init,-1,-1,-1,-1);
%%backgroundimage:images/lam_init.jpg,-2739.89,-912.447,1,0,0,1

%%beginverbatim

%%endverbatim

%%beginpaths

fill
bldmv ( (156,33), (-270,-84), (18,-13) ) leftjoin
bldmv ( (118,97), (-137,-47), (24,-5) ) .. tension 1 and 2.44099 ..
 {up}(148,117) .. tension 25.9148 and 27.8321 ..
(86,504) .. tension 3.1828 and 0.75 ..
 {up}(60,566) .. tension 2.23645 and 1.57926 ..
 {right}(107,679) .. tension 1.85207 and 1.33449 ..
(136,594) .. tension 1.34175 and 1.47482 ..
 {down}(183,569) .. tension 0.75 and 4.0387 ..
(146,483) .. tension 14.0434 and 2.26495 ..
 {down}(200,134) .. tension 1 and 1 ..
 cycle
;

%%endpaths
%%beginbody

enddefchar;
defchar(lam.init.beforebeh,-1,-1,-1,-1);
%%backgroundimage:images/lambeh.jpg,-1179,-1096,1,0,0,1

%%beginverbatim

behbeh_(0,0);

save p,time,points; path p; numeric time[]; pair points[];

p := pathpart currentpicture;


(time1,whatever) = p intersectiontimes z1;
(time2,whatever) = p intersectiontimes z2;

points1 := direction time1 of p;
points2 := direction time2 of p;


currentpicture:=nullpicture;
%%endverbatim

%%beginpaths

fill
(312.816,636.578) .. tension 1.49749 and 1.2429 ..
(341.019,555) .. tension 1 and 0.75 ..
 {down}(384.019,523) .. tension 0.75 and 1 ..
 {down}(350,430) .. tension 1.23001 and 1 ..
 {down}(392.019,144) .. tension 1 and 1.55111 ..
(358.788,38.1055) .. tension 1 and 1 ..
 {points2}z2 .. tension 1.98577 and 1 ..
 {up}(276.736,58.1501) .. tension 1 and 1.47124 ..
 {points1}z1 .. tension 0.75 and 0.75 ..
 {up}(332.01,136.3) .. tension 1.7631 and 1 ..
(309.019,280) .. tension 1 and 3.38685 ..
(281.019,482) .. tension 1 and 0.75 ..
 {up}(263.861,520.622) .. tension 3.03106 and 2.6677 ..
 {right} cycle
;

%%endpaths
%%beginbody
leftanchor:=z2;

enddefchar;
defchar(lam.init.beforeyeh,-1,-1,-1,-1);
%%backgroundimage:images/lam_yeh.jpg,-440.6,-925.2,1,0,0,1
%%beginparams
z1 = (46,-44);

%%beginpaths

fill
z1 .. tension 1 and 1.80573 ..
 {up}(22.7949,-32.5673) .. tension 0.931123 and 3.10589 ..
(48.9392,32.006) .. tension 9.35828 and 1.723 ..
 {up}(155.446,95.477) .. tension 4.13979 and 12.9449 ..
(73.7566,494.676) .. tension 3.29886 and 1 ..
 {up}(47.8024,551.525) .. tension 1.75176 and 2.5099 ..
 {right}(92.4686,670.38) .. tension 2.01426 and 1.83084 ..
(126.631,572.962) .. tension 1.54652 and 1.39398 ..
 {down}(162.476,554.444) .. tension 1 and 1.50717 ..
 {down}(139.505,482.646) .. tension 2.63614 and 1.12218 ..
 {down}(201.801,101.67) .. tension 1.68905 and 1.53 ..
 {left} cycle
;

%%endpaths
%%beginbody

leftbearing := 0;
rightbearing:=70;


setCursiveAnchor(ltrcursive,z1,ExitAnchor);

enddefchar;
defchar(lam.init.lam_hah,-1,-1,-1,-1);
%%backgroundimage:images/lam_hah.jpg,-1537.5,-954.167,1,0,0,1
%%beginparams
z1 = (126,154);

%%beginverbatim
%%backgroundimage:images/lam.init_hah.jpg,-1632,-1020,1,0,0,1
%%backgroundimage:images/behhah.jpg,-1665.24,-1053.77,1,0,0,1
%%endverbatim

%%beginpaths

fill
(123,139) .. tension 2.86153 and 2.86153 ..
z1 {dir behshape.init.beforehah.dir1} .. tension 1.50597 and 5.48651 ..
 {up}(308,193) .. tension 4.6939 and 6.8484 ..
(258,529) .. tension 1.66263 and 0.966451 ..
 {up}(234,600) .. tension 1.88324 and 7.2459 ..
 {right}(284,716) .. tension 2.58251 and 4.45854 ..
(311,643) .. tension 1.77368 and 1.77368 ..
 {down}(359,599) .. tension 1.17354 and 4.55519 ..
 {down}(322,536) .. tension 4.87812 and 4.96004 ..
 {down}(372,164) .. tension 0.75 and 3.30683 ..
 {left}(292,114) .. tension 0.75 and 4.17622 ..
 {up} cycle
;

%%endpaths
%%beginbody

rightbearing :=  300;
leftbearing := -150;



setCursiveAnchor(rtlcursive,z1, ExitAnchorRTL);



enddefchar;
defchar(lam.init.beforehahyeh,-1,-1,-1,-1);
%%beginbody

lam.init.lam_hah_(0,0);
setCursiveAnchor(rtlcursive,z1 , ExitAnchorRTL);

enddefchar;
defchar(lam.init.beforedal,-1,-1,-1,-1);
%%backgroundimage:images/lam_dal.jpg,-1838,-1134,1,0,0,1

%%beginverbatim


minLeft := 0.5;

lefttatweel := lefttatweel -0.4;

%%endverbatim

%%beginpaths

fill
bldmvi ( (90.3354,8.40162), (-12.5974,-7.26775) ) leftjoin
bldmvi ( (87.6862,98.5863), (-29.1486,-13.6104) ) .. tension 1 and bldmvi ( 1.06519, 0.2 ) ..
 {up}(99.405,116.557) .. tension 25.9148 and 27.8321 ..
(33.399,538.033) .. tension 3.1828 and 0.75 ..
 {up}(7.1056,603.19) .. tension 2.23645 and 2.62674 ..
 {right}(56.6682,711.558) .. tension 2.19039 and 1.33449 ..
(83.5216,625.977) .. tension 1.34175 and 1.47482 ..
 {down}(127.917,603.509) .. tension 0.75 and 4.0387 ..
(94.2511,515.555) .. tension 14.0434 and 2.26495 ..
 {down}(145.865,128.952) .. tension bldmvi ( 18.7115, -0.3 ) and 1.04836 ..
 cycle
;

%%endpaths
%%beginbody

enddefchar;
defchar(lam.medi,-1,-1,-1,-1);
%%backgroundimage:images/lam.medi.jpg,-1180.26,-1171.07,1,0,0,1
%%beginparams
leftVerticalRatio := 10;
rightVerticalRatio := 10;

%%beginverbatim

%minRight:=-0.5;

%%endverbatim

%%beginpaths

fill
(150,151) .. tension 3.49539 and 1 ..
(117.869,394.882) .. tension 3.43687 and 13.4898 ..
 {up}(82,670) .. tension 1.60026 and 2.03022 ..
 {right}(120,735) .. tension 14.0746 and 7.85072 ..
brdmv ( (219,129), (-4.86111,29.1667), (4.09013,-36.3263) ) setranchor
(276,0) rightjoinii
bldmv ( (160,65), (0,-14), (0,0) ) leftjoin
bldmv ( (139,126), (7.20961,17.21), (8.56626,-21.9777) ) .. tension 1 and 1.51257 ..
 {up} cycle
;

%%endpaths
enddefchar;
defchar(lam.medi.afterkaf,-1,-1,-1,-1);
%%backgroundimage:images/kaf_lam.jpg,-629,-1031,1,0,0,1
%%beginbody


lam.medi_(lefttatweel,0.1);
enddefchar;
defchar(lam.medi.beforeheh,-1,-1,-1,-1);
%%backgroundimage:images/lam_heh.jpg,-552,-1067.33,1,0,0,1
%%beginparams
leftVerticalRatio := 10;
rightVerticalRatio := 10;

%%beginverbatim

%minRight:=-0.5;

%%endverbatim

%%beginpaths

fill
(62.0671,131.94) .. tension 3.49539 and 1 ..
(40.369,373.215) .. tension 3.43687 and 13.4898 ..
 {up}(0.278367,645.833) .. tension 1.60026 and 2.03022 ..
 {right}(35.873,712.974) .. tension 13.7116 and bldmvi ( 3.07376, 20 ) ..
brdmv ( (130.491,208.093), (15.9722,-31.6666), (4.09013,-36.3263) ) setranchor
(195.768,58.486) rightjoinii
(107.271,110.071) leftjoin
bldmv ( (43.9484,96.9046), (7.20961,17.21), (4.88393,-21.3963) ) .. tension 1 and 1.51257 ..
 {up} cycle
;

%%endpaths
enddefchar;
defchar(lam.medi.beforeyeh,-1,-1,-1,-1);
%%backgroundimage:images/lam.medi_yeh.fina.jpg,-390.768,-911.412,1,0,0,1
%%beginparams
leftVerticalRatio := 10;
rightVerticalRatio := 10;
z1 = (2,-108);
z3 = z1 + (76,83);

%%beginverbatim

%minRight:=-0.5;

%%endverbatim

%%beginpaths

fill
(52,107) .. tension 3.49539 and 1 ..
(44,265) .. tension 3.43687 and 13.4898 ..
 {up}(15,523) .. tension 1.60026 and 2.03022 ..
 {right}(52,596) .. tension 7.70954 and 10.129 ..
(98,358) .. tension bldmvi ( 3.07376, 20 ) and bldmvi ( 3.07376, 20 ) ..
brdmv ( (144,143), (6.71294,-7.36104), (-8.06265,-40.3772) ) setranchor
(210,0) rightjoinii
(100,60) {dir -96.2313} .. tension 1.54833 and 1.05538 ..
z3 .. tension 1 and 1 ..
 {left}z1 .. tension 0.914444 and 1 ..
(-8,-89) {up} .. tension 4.40627 and 0.883604 ..
 {up} cycle
;

%%endpaths
%%beginbody
leftbearing := 0;



setCursiveAnchor(ltrcursive,z1,ExitAnchor);
enddefchar;
defchar(lam.fina,-1,-1,-1,-1);
%%backgroundimage:images/lam.fina.jpg,73.052,-948.443,1,0,0,1

%%beginverbatim

rightVerticalRatio := 5;

%%endverbatim

%%beginpaths

fill
(116,-100) .. tension 1 and 3.93398 ..
 {right}(206,85) .. tension 1 and 1 ..
 {down}(218,66) .. tension 1.11576 and 1 ..
 {down}(177,-49) .. tension 0.943093 and 0.873211 ..
 {right}(338,-172) .. tension 1.15616 and 2.83043 ..
 {up}(509,-83) .. tension 18.5463 and 4.51974 ..
 {up}(438,558) .. tension 1.1566 and 2.11456 ..
 {right}(474,645) .. tension 6.24161 and 0.817189 ..
(525,329.083) .. tension 1 and 1.58225 ..
brdmv ( (567,170), (24,-20), (-22,-43) ) setranchor
(627,0) rightjoinii
(556.25,58.9445) {curl1} .. tension 6.5984 and 1 ..
 {down}(557,-55) .. tension 1.07609 and 1 ..
 {left}(297,-266) .. tension 1 and 1 ..
 {up} cycle
;

%%endpaths
enddefchar;
defchar(lam.fina.afterkaf,-1,-1,-1,-1);
%%beginbody

lam.fina_(lefttatweel,righttatweel+0.3);

enddefchar;
beginchar(meem.isol.ii,-1,-1,-1,-1);
%%backgroundimage:images/meem.isol.jpg,50.1579,-922.28,1,0,0,1

%%beginpaths

fill
(137,-123) .. tension 3.03213 and 2.76898 ..
 {up}(429,63) .. tension 0.75 and 0.75 ..
 {up}(412,106) .. tension 2.11074 and 1.74829 ..
 {right}(560,287) .. tension 1.58938 and 1.79756 ..
 {down}(639,100) .. tension 0.819851 and 2.34269 ..
 {left}(597,24) .. tension 0.877444 and 1.4779 ..
 {left}(480,44) .. tension 17.0416 and 0.75 ..
(406,-36) .. tension 1.33087 and 2.90555 ..
 {left}(159,-138) .. tension 1 and 1 ..
 {up} cycle
;
fill
(479,150) .. tension 4.59561 and 1 ..
 {right}(547,119) .. tension 1 and 1 ..
 {up}(564,131) .. tension 6.14356 and 2.20122 ..
 {left}(533,196) .. tension 0.932393 and 5.78647 ..
 {down} cycle
;

%%endpaths
%%beginbody

endchar;
beginchar(meem.isol,1605,-1,-1,-1);
%%backgroundimage:images/meemii2.isol.jpg,58.3831,-957.421,1,0,0,1

%%beginpaths

fill
(205,216) {up} .. tension 1.20071 and 1.56488 ..
 {right}(306,348) .. tension 1.96675 and 17.0635 ..
 {down}(449,217) .. tension 1 and 4.50003 ..
 {left}(415,135) .. tension 8.09822 and 2.6964 ..
 {left}(339,131) .. tension 2.70682 and 2.79538 ..
 {down}(189,93) .. tension 2.96404 and 1.20427 ..
 {down}(231,-281) .. tension 1 and 1.60465 ..
 {left}(203,-353) .. tension 0.993256 and 1.65815 ..
(187,-327) .. tension 1.63032 and 2.73205 ..
 {up}(139,22) .. tension 0.881308 and 0.75 ..
 {dir 8.2577}(324,215) {dir 115.703} .. tension 2.18133 and 1 ..
 {left}(279,245) .. tension 0.966248 and 2.84235 ..
 {left}(217,201) .. tension 1.03949 and 1 ..
 cycle
;

%%endpaths
%%beginbody

endchar;
defchar(meem.init,-1,-1,-1,-1);
%%backgroundimage:images/meem.init.jpg,-1931.04,-1039.59,1,0,0,1

%%beginverbatim



%%endverbatim

%%beginpaths

fill
bldmv ( (119,151), (20,40), (1,0) ) .. tension 1 ..
(195,244) .. tension 1 and 1.53351 ..
 {right}(267,294) .. tension 1.72407 and 1.83398 ..
 {down}(355,125) .. tension 1.20926 and 3.07538 ..
 {left}(314,29) .. tension 0.790113 and 1.39505 ..
(210,40) .. tension 1 and 3.31851 ..
 {left}(131,86) .. tension bldmvi ( 1.80517, 3.2 ) and 1 ..
bldmv ( (95,48), (-123,-49), (60,50) ) leftjoin
bldmv ( bldmvi ( (97,121), (-9.00828,-8.97162) ), (20,27), (-30,-59) ) .. tension atleast 3.56302 ..
 cycle
;
fill
(278,136) .. tension 6.08809 and 1.12262 ..
 {left}(239,198) .. tension 1.0287 and 2.48927 ..
(193,162) {down} .. tension 9.88547 and 2.04959 ..
 {up} cycle
;

%%endpaths
%%beginbody



%labels(1,2);
enddefchar;
defchar(meem.init.beforeyeh,-1,-1,-1,-1);
%%backgroundimage:images/meem_yeh.jpg,-526.588,-1133.4,1,0,0,1
%%beginparams
z1 = (-75,1);

%%beginverbatim

z3 = z1 + (76,83);

%%endverbatim

%%beginpaths

fill
z1 .. tension 1 and 1.00891 ..
 {up}(-92,34) .. tension 1.57522 and 1 ..
(44,206) .. tension 4.14884 and 2.72588 ..
 {up}(106,243) .. tension 1.83772 and 1 ..
(100,276) .. tension 1 and 1.41817 ..
 {right}(190,391) .. tension 1.5804 and 1.83398 ..
 {down}(303,301) .. tension 1.08167 and 5.01752 ..
(199,187) .. tension 3.26099 and 0.760258 ..
z3 .. tension 2.61533 and 2.61533 ..
 {left} cycle
;

%%endpaths
%%beginbody
leftbearing := 0;

setCursiveAnchor(ltrcursive,z1,ExitAnchor);
enddefchar;
defchar(meem.init.beforehah,-1,-1,-1,-1);
%%backgroundimage:images/behhah.jpg,-1843.24,-861.77,1,0,0,1
%%beginparams
z1 = (-60,51);

%%beginverbatim


%%endverbatim

%%beginpaths

fill
z1 {dir behshape.init.beforehah.dir1} .. tension 1.22088 and 1 ..
(-50,57) .. tension 1.17845 and 1.29781 ..
(195,146) {dir 10.3408} .. tension 0.813189 and 1 ..
 {up}(200,174) .. tension 1.3562 and 1.3562 ..
 {right}(262,276) .. tension 1.5804 and 1.83398 ..
 {down}(379,188) .. tension 1.08167 and 5.01752 ..
(297,93) .. tension 9.72324 and 6.35808 ..
 {left}(-26,9) .. tension 1 and 0.75 ..
 {up} cycle
;

%%endpaths
%%beginbody

tr_ := tr_ shifted (0,140 );
leftbearing := -200 ;
rightbearing := 150;
setCursiveAnchor(rtlcursive,z1, ExitAnchorRTL);
enddefchar;
defchar(meem.medi,-1,-1,-1,-1);
%%backgroundimage:images/meem.medi.jpg,-2316.16,-1168.44,1,0,0,1
%%beginparams
leftVerticalRatio := 10;
rightVerticalRatio := 10;

%%beginverbatim





%%endverbatim

%%beginpaths

fill
(258,248) .. tension 1.22114 and 3.27133 ..
brdmv ( (313,200), (37,-32), (-1,-9) ) .. tension 1.58165 and 1.58165 ..
brdmv ( (391,112), (14,9), (-16,-23) ) setranchor
brdmv ( (486,0), (0,0), (0,0) ) rightjoinii
brdmv ( (372,35), (0,0), (-13,-30) ) {curl1} .. tension 3.23319 and 1.72706 ..
 {left}(352,2) .. tension 0.75 and 2.79227 ..
(243,15) .. tension 1 and 1.6801 ..
 {curl1}(158,70) leftjoin
bldmv ( (150,159), (0,0), (-6,-45) ) .. tension 1 and 0.906587 ..
 {right} cycle
;
fill
(205,154) .. tension 1.25647 and 2.25403 ..
 {right}(275,108) .. tension 1 and 1.55588 ..
 {up}(284,113) .. tension 3.60518 and 3.7975 ..
 {left}(233,178) .. tension 1.56086 and 4.27536 ..
 {down} cycle
;

%%endpaths
%%beginbody

enddefchar;
defchar(meem.medi.afterhah,-1,-1,-1,-1);
%%backgroundimage:images/hah_meem.jpg,-1003.17,-1197.95,1,0,0,1
%%beginparams
hahmeem.dir.1 := 20;
z1 = (171,209);

%%beginverbatim

%%endverbatim

%%beginpaths

fill
(309,72) .. tension 1.11778 and 1.02193 ..
 {left}(227,-14) .. tension 1.59086 and 1.15466 ..
 {dir 97.1114}bldmv ( (96,94), (3,-25), (23,-72) ) leftjoin
bldmv ( (76,121), (-26,-13), (31,18) ) .. tension 1.12755 and 0.889786 ..
 {dir hahmeem.dir.1}z1 .. tension 0.75 and 1.10448 ..
 {down} cycle
;
fill
(251,86) {curl1} .. tension 2.36269 and 0.75 ..
 {left}(161,147) .. tension 1.52875 and 1.48793 ..
(141,142) {down} .. tension 2.23621 and 2.70395 ..
 {up} cycle
;

%%endpaths
%%beginbody


setCursiveAnchor(rtlcursive,z1,EntryAnchorRTL);
enddefchar;
defchar(meem.medi.beforeyeh,-1,-1,-1,-1);
%%backgroundimage:images/meem.medi_yeh.jpg,-374.035,-918,1,0,0,1
%%beginparams
z1 = (34,-81);

%%beginverbatim







%%endverbatim

%%beginpaths

fill
(169,-18) .. tension 1 and 1 ..
 {left}z1 .. tension 1.24663 and 0.818793 ..
 {up}(5,-62) .. tension atleast 1.6931 ..
(61,-3) .. tension 2.43688 and 0.75 ..
(195,71) .. tension 0.75 and 1.43202 ..
 {right}(359.331,215.577) .. tension 2.82523 and 1.58165 ..
(424,158) .. tension 1.21643 and 1.01257 ..
brdmv ( (496,102), (0,0), (6,-22) ) setranchor
(558,0) rightjoinii
brdmv ( (484,24), (0,0), (-9,-33) ) {dir -94.3461} .. tension 2.63339 and 2.93508 ..
 {left}(449,-15) .. tension 1 and 2.79227 ..
(332,3) .. tension 1 and 1.6801 ..
 {curl1}(255,48) .. tension 2.77486 and 1 ..
 cycle
;
fill
(310,117) .. tension 2.87484 and 5.66398 ..
 {up}(382,89) .. tension 3.85484 and 1.35829 ..
 {left}(335,146) .. tension 0.75 and 1.6549 ..
 {down} cycle
;

%%endpaths
%%beginbody
leftbearing := 0 ;
setCursiveAnchor(ltrcursive,z1,ExitAnchor);

enddefchar;
defchar(meem.fina,-1,-1,-1,-1);
%%backgroundimage:images/meem.fina.jpg,-179,-920,1,0,0,1
%%beginparams
z.mark1 = (218,-159);

%%beginverbatim

righttatweel := righttatweel - 0.3;

%%endverbatim

%%beginpaths

fill
(152,39) .. tension 0.75 and 1 ..
 {up}(142,80) .. tension 1.73037 and 1.61706 ..
 {right}(273,225) .. tension 2.84357 and 1 ..
(327,166) .. tension 1 and 1 ..
brdmv ( (393,114), (99,-37), (-10,-27) ) setranchor
(496,-3) rightjoinii
brdmv ( (389,21), (0,0), (-1,-25) ) {curl1} .. tension 1.3164 and 2.03251 ..
 {left}(362,-16) .. tension 1.46691 and 6.1513 ..
 {left}(198,4) .. tension 5.41352 and 5.43489 ..
(122,-54) .. tension 0.989106 and 18.3373 ..
 {left}(-77,-102) .. tension 1 and 1 ..
 {up}(-90,-91) .. tension 2.77906 and 1 ..
(-8,-48) .. tension 1.73988 and 6.20895 ..
 {up} cycle
;
fill
(240,144) .. tension 1.23804 and 1.74187 ..
 {down}(213,115) .. tension 6.28125 and 2.6024 ..
 {up}(274,88) .. tension 1.82811 and 3.01664 ..
 {left} cycle
;

%%endpaths
%%beginbody
%%beginbody


setMarkAnchor(buttonmark,z.mark1);

enddefchar;
defchar(meem.fina.afterheh,-1,-1,-1,-1);
%%backgroundimage:images/kaf_meem.jpg,-565,-1125,1,0,0,1
%%beginparams
z1 = (-2,48);
z2 = (-111,99);

%%beginverbatim

%%endverbatim

%%beginpaths

fill
(-512,-231) .. tension 2.3795 and 1 ..
(-388,-188) .. tension 1.34427 and 4.24422 ..
 {up}(-173,-75) .. tension 2.44071 and 1 ..
 {up}(-186,-23) .. tension 1.43668 and 1.43668 ..
z2 {dir 35} .. tension 0.847258 and 0.847258 ..
 {right}(-58,114) .. tension 1.58938 and 1.03381 ..
 {down}(49,-23) .. tension 1.49551 and 1.0177 ..
 {left}(-29,-154) .. tension 1 and 4.52521 ..
 {left}(-142,-120) .. tension 29.5546 and 0.75 ..
(-195,-178) .. tension 1.33087 and 1.32657 ..
 {left}(-491,-244) .. tension 1 and 1 ..
 {up} cycle
;
fill
(-125,1) .. tension 4.59561 and 1.27641 ..
 {right}(-35,-46) .. tension 1 and 1 ..
 {up}(-28,-40) .. tension 1.43117 and 2.20122 ..
 {left}(-100,21) .. tension 0.799344 and 1.36615 ..
 {down} cycle
;

%%endpaths
%%beginbody
setCursiveAnchor(hehmeem,z2, EntryAnchor);
setCursiveAnchor(kafmeem,z1, EntryAnchor);

enddefchar;
defchar(meem.fina.afterkaf,-1,-1,-1,-1);
%%beginbody
meem.fina.afterheh_(0,0);
enddefchar;
defchar(meem.fina.ii,-1,-1,-1,-1);
%%backgroundimage:images/meemii.fina.jpg,51.0556,-976.518,1,0,0,1

%%beginverbatim

%%endverbatim

%%beginpaths

fill
(87,-57) .. tension 0.75 and 1 ..
(104,43) .. tension 1 and 1 ..
(252,120) {right} .. tension 1.34941 and 1.34941 ..
 {right}(299,184) .. tension 1.32087 and 1 ..
(338,124) setranchor
(473,0) rightjoinii
(407,5) {curl1} .. tension 5.56372 and 1.45592 ..
 {left}(359,-129) .. tension 0.951104 and 258.017 ..
 {left}(268,28) .. tension 1.47039 and 1.94979 ..
 {down}(135,-16) .. tension 10000 and 1.35851 ..
 {down}(189,-434) .. tension 1.84582 and 1.35324 ..
 {left}(162,-487) .. tension 2.15169 and 4.59968 ..
(129,-374) .. tension 2.30836 and 2.30836 ..
 {up} cycle
;

%%endpaths
%%beginbody

enddefchar;
beginchar(noon.isol,1606,-1,-1,-1);
%%backgroundimage:images/noon_isol2.jpg,-24,-1206,1,0,0,1
%%beginparams
z11 = (173,334);
z2 = (481,144);
%%beginbody
noonshape.isol_(0,0);
draw one_dot.pic  shifted z11;


setCursiveAnchor(rtlcursive,z2, EntryAnchorRTL);
endchar;
defchar(noon.fina,-1,-1,-1,-1);
%%backgroundimage:images/noon.fina.jpg,-36.029,-941.59,1,0,0,1
%%beginparams
z11 = (198,151);

%%beginverbatim



%%endverbatim
%%beginbody
noonshape.fina_(lefttatweel,righttatweel);
draw one_dot.pic  shifted z11;



enddefchar;
defchar(noon.fina.afterbeh,-1,-1,-1,-1);
%%backgroundimage:images/noon_isol2.jpg,-27,-960,1,0,0,1
%%beginparams
z1 = (173,351);
z2 = (478,148);

%%beginverbatim
righttatweel := charrt -0.5;

%%endverbatim
%%beginbody
noonshape.isol_(0,0);
draw one_dot.pic  shifted z1;

setCursiveAnchor(rtlcursive,z2, EntryAnchorRTL);


enddefchar;
defchar(qaf.isol,1602,-1,-1,-1);
%%backgroundimage:images/qaf.isol.jpg,25,-1026,1,0,0,1
%%beginparams
z1 = (324.079,-114.63);
z11 = (315,437);
z2 = z1 + joinvector;

%%beginpaths

fill
(149.231,23.2639) .. tension 0.75 and 5.5838 ..
 {right}(229.287,197.287) .. tension 1 and 1 ..
 {down}(244.917,176.236) .. tension 1.24527 and 1 ..
 {down}(215.963,79.8981) .. tension 1 and 1 ..
 {right}z2 .. tension 1.08626 and 1.6787 ..
 {up}(549,88.2546) .. tension 1 and 2.26133 ..
 {left}(531.472,134.009) .. tension 33.0823 and 0.75 ..
 {left}(475,103) .. tension 1 and 1 ..
 {up}(393,195) .. tension 1 and 1.97716 ..
 {right}(478,353) .. tension 1.57954 and 1.68112 ..
 {down}(606.315,135.421) .. tension 0.957641 and 1.02927 ..
(577,0) .. tension 1.28094 and 1.01553 ..
 {left}z1 .. tension 0.805762 and 1.37055 ..
 {up} cycle
;
fill
(470.046,250.218) .. tension 1.00346 and 2.4594 ..
 {down}(452.62,229.843) .. tension 1.59598 and 0.837748 ..
 {right}(480.884,203.579) .. tension 1 and 2.1614 ..
 {up}(494.787,224.736) .. tension 2.69079 and 1 ..
 {left} cycle
;

%%endpaths
%%beginbody




draw two_dots.pic  shifted z11;
savepicture:=1;
enddefchar;
defchar(feh.isol,1601,-1,-1,-1);
%%backgroundimage:images/feh.isol.jpg,-104,-1102.27,1,0,0,1
%%beginparams
z11 = bldmvi ( (337,519), (829,-1) );

%%beginverbatim
lefttatweel := lefttatweel - 0.5;

minLeft := 0;
maxLeft := 7;

%y33 := - minLeft *nuqta;

%%endverbatim

%%beginpaths

fill
(5,135) .. tension 1.47376 and 2.37253 ..
 {right}(97,299) .. tension 0.75 and 2.19563 ..
 {down}(107,283) .. tension 2.87221 and 0.75 ..
 {down}(63,172) .. tension bldmvi ( bldmvi ( 1.20675, 0.812456 ), -0.2 ) and 1.03433 ..
 {right}bldmvi ( (299,49), (343.008,-51.264) ) .. tension 1 and bldmvi ( 7.36562, 0.6 ) ..
 {up}bldmvi ( (753,145), nuqta * (7,0) ) .. tension 0.75 and 1.4241 ..
 {left}bldmvi ( bldmvi ( (731,193), (0,0) ), (832,-3) ) .. tension 1.86984 and 0.766661 ..
 {left}bldmvi ( (661,150), (832,-3) ) .. tension 2.08404 and 0.832524 ..
 {up}bldmvi ( (572,235), nuqta * (7,0) ) .. tension 1.41144 and 1.49627 ..
 {right}bldmvi ( (669,414), nuqta * (7,0) ) .. tension 2.56964 and 0.867889 ..
 {down}bldmvi ( (801,172), nuqta * (7,0) ) .. tension bldmvi ( 2.54178, -0.55 ) and 0.849674 ..
bldmvi ( (738.826,49.6676), (821,0) ) .. tension 2.67069 and 0.85511 ..
 {left}bldmvi ( (321,-38), (332.592,-45.312) ) .. tension bldmvi ( 0.888303, 0 ) and bldmvi ( 0.985011, 0.7 ) ..
 {bldmvi ( up, (0,0) )} cycle
;
fill
bldmvi ( (704,276), (833,-2) ) .. tension 1.95936 and 1 ..
 {left}bldmvi ( (659,317), (833,-2) ) .. tension 2.13457 and 1 ..
 {down}bldmvi ( (623,280), (833,-2) ) .. tension 1 and 1 ..
 {right}bldmvi ( (674,244), (833,-2) ) .. tension 1 and 1 ..
 cycle
;

%%endpaths
%%beginbody

draw one_dot.pic  shifted z11;
savepicture:=1;

enddefchar;
defchar(qaf.fina,-1,-1,-1,-1);
%%backgroundimage:images/qaf.fina.2.jpg,23.3403,-932.127,1,0,0,1
%%beginparams
z1 = (489,229);
z11 = (281,329);
z2 = (465,142);

%%beginverbatim


%%endverbatim

%%beginpaths

fill
(68,-38) .. tension 1 and 6.41744 ..
 {right}(156,128) .. tension 1 and 1 ..
 {down}(167,111) .. tension 7.13715 and 1 ..
 {down}(120,1) .. tension 1 and 1 ..
 {right}(310,-151) .. tension 0.75 and 5.38906 ..
 {up}(573,-54) .. tension 1 and 4.47302 ..
(531,72) .. tension 1.51898 and 1 ..
(487,132) .. tension 0.890434 and 1.4933 ..
 {left}z2 .. tension 5.44047 and 3.40173 ..
 {right}z1 .. tension 1.28201 and 4.69626 ..
(615,33) {curl1} .. tension 1.43469 and 1 ..
(606,-86) .. tension 1.20455 and 1 ..
 {left}(276,-231) .. tension 1 and 1 ..
 {up} cycle
;
fill
(400,37) .. tension 1 and 1 ..
(388,84) .. tension 1 and 1 ..
(429,180) .. tension 1 and 1.34802 ..
z1 {right} .. tension 3.00215 and 4.73364 ..
z2 {left} .. tension 1 and 2.13928 ..
 {down}(444,113) .. tension 1.08819 and 1 ..
(449,97) link
(509,-1) ..
 cycle
;

%%endpaths
%%beginbody
drawcomp(two_dots,identity shifted z11);
enddefchar;
defchar(qaf.fina.expa,-1,-1,-1,-1);
%%beginparams
z.two_dots = (275,365);
z1 = (482,256);
z2 = (450,167);

%%beginverbatim


minLeft := 0;
maxLeft := 4.7;

%%endverbatim

%%beginpaths

fill
bldmvi ( (-219,36), (-maxLeft * nuqta,-1) ) .. tension 1.23926 and 0.75 ..
 {right}bldmvi ( (-209,52), (-558,0) ) .. tension 10000 and 1 ..
bldmvi ( (-170,19), (-550,-8) ) .. tension 1 and bldmvi ( 1, 0.1 ) ..
 {right}bldmvi ( (201,-138), (-255,-71) ) .. tension 1 and bldmvi ( 3.67654, -0.1 ) ..
 {up}(551,-18) .. tension 0.86298 and 4.47302 ..
(480,143) .. tension 0.890434 and 1.4933 ..
 {left}z2 .. tension 5.44047 and 3.40173 ..
 {right}z1 .. tension 3.46951 and 1.61702 ..
 {down}(608,43) .. tension 0.75 and 1.281 ..
bldmvi ( (561,-93), (-25,-32) ) .. tension 1.6893 and 0.75 ..
 {left}bldmvi ( (191,-216), (-258,-74) ) .. tension bldmvi ( 1.07207, 0.1 ) and 0.873173 ..
bldmvi ( (-130,-101), (-545,-12) ) .. tension 0.873173 and 0.873173 ..
bldmvi ( (-200,-13), (-560,2) ) .. tension 4.05368 and 2.19145 ..
 {up} cycle
;
fill
(384,49) .. tension 1 and 1 ..
 {up}(377,93) .. tension 1.06192 and 2.73766 ..
z1 {right} .. tension 3.00215 and 4.73364 ..
z2 {left} .. tension 2.21643 and 1.47953 ..
 {down}(425,127) .. tension 1.08819 and 1 ..
(431,106) link
(527,0) ..
 cycle
;

%%endpaths
%%beginbody
draw two_dots.pic shifted z.two_dots;

enddefchar;
defchar(fehshape.init,-1,-1,-1,-1);
%%backgroundimage:images/qaf.init.jpg,-2240.16,-1180.66,1,0,0,1

%%beginverbatim

%%endverbatim

%%beginpaths

fill
liii0 ( (103.339,5.3741), (-4.62963,-10.9954), (64.9352,-1.94444) ) leftjoin
liii0 ( (178.397,117.521), (-5.00463,-5.68519), (23.1574,0.944444) ) .. tension 1 and 2.17887 ..
 {up}(211.723,139.639) .. tension 0.75 and 1.94537 ..
 {left}(203.112,161.963) .. tension 5.38414 and 0.75 ..
 {left}(131.829,129.69) .. tension 0.786927 and 2.08491 ..
 {up}(61.0122,219.596) .. tension 0.962383 and 1.94228 ..
 {right}(148.617,370.93) .. tension 2.86485 and 1.2293 ..
 {down}(275.239,160.229) .. tension 0.959834 and 1 ..
(204.288,37.1737) .. tension 1 and 1.63088 ..
 cycle
;
fill
(122.063,243.785) .. tension 0.873175 and 2.02774 ..
 {right}(154.61,223.125) .. tension 1 and 2.05693 ..
 {up}(164.823,237.09) .. tension 2.16369 and 1.13985 ..
 {left}(133.915,271.033) .. tension 1.60243 and 1.41932 ..
 {down} cycle
;

%%endpaths
%%beginbody

enddefchar;
defchar(fehshape.init.beforehah,-1,-1,-1,-1);
%%backgroundimage:images/feh_hah.jpg,-2077.34,-1010.55,1,0,0,1
%%beginparams
z1 = (-95,80);

%%beginverbatim
%%backgroundimage:images/behhah.jpg,-1665.24,-1053.77,1,0,0,1
%%backgroundimage:images/feh_hah.jpg,-2070,-1005,1,0,0,1

%%endverbatim

%%beginpaths

fill
(134,63) .. tension 1.10015 and 1 ..
 {left}(10,38) .. tension 1 and 3.42037 ..
 {up}(-103,67) .. tension 0.75 and 1.28547 ..
z1 {dir behshape.init.beforehah.dir1} .. tension 2.21929 and 3.10174 ..
 {up}(151,149) .. tension 3.75901 and 3.3084 ..
 {left}(140,212) .. tension 4.28107 and 0.75 ..
 {left}(61,157) .. tension 0.831576 and 2.08491 ..
 {up}(-27,235) .. tension 0.90666 and 2.70287 ..
 {right}(67,415) .. tension 1.69552 and 0.924395 ..
 {down}(191,197) .. tension 1.18307 and 1.36164 ..
 cycle
;
fill
(30,280) .. tension 1 and 1.46882 ..
 {right}(66,247) .. tension 1.38247 and 1.19098 ..
 {up}(104,271) .. tension 2.96303 and 1.10769 ..
 {left}(55,319) .. tension 1.60243 and 1 ..
 {down} cycle
;

%%endpaths
%%beginbody

rightbearing :=  280;
leftbearing := -150;

setCursiveAnchor(rtlcursive,z1, ExitAnchorRTL);

enddefchar;
defchar(fehshape.init.beforeyeh,-1,-1,-1,-1);
%%backgroundimage:images/fehyeh.jpg,-404.204,-722.179,1,0,0,1
%%beginparams
z1 = (47,87);

%%beginpaths

fill
(1.42535,334.373) .. tension 0.895824 and 2.08468 ..
 {right}(98.9474,520.911) .. tension 1.76956 and 1.83281 ..
 {down}(227.141,296.759) .. tension 1.08046 and 1.08046 ..
(180.023,167.274) .. tension 3.74249 and 1.37974 ..
 {left}z1 .. tension 0.75 and 1.32883 ..
 {up}(18.5577,103.689) .. tension 1.7336 and 1.92586 ..
(53.6749,164.938) .. tension 3.33363 and 1.11485 ..
 {up}(177.518,254.062) .. tension 1.40417 and 2.57407 ..
 {left}(166.23,302.679) .. tension 4.91627 and 0.753809 ..
 {left}(88.1638,257.48) .. tension 1 and 1.29391 ..
 {up} cycle
;
fill
(50.0525,390.635) .. tension 0.915561 and 1.38577 ..
 {right}(103.971,355.74) .. tension 1 and 1.44268 ..
 {up}(131.165,366.054) .. tension 5.6761 and 1.4191 ..
 {left}(84.0787,424.795) .. tension 1.36248 and 1.24129 ..
 {down} cycle
;

%%endpaths
%%beginbody
leftbearing := 0;
rightbearing:= 60;


setCursiveAnchor(ltrcursive,z1,ExitAnchor);
enddefchar;
defchar(fehshape.medi,-1,-1,-1,-1);
%%backgroundimage:images/feh.medi.jpg,-1984.61,-1218.02,1,0,0,1
%%beginparams
z1 = (197.334,346.111);
z2 = (168.22,248.555);

%%beginverbatim

%lefttatweel := lefttatweel - 0.5;
%righttatweel := righttatweel - 0.5;

%%endverbatim

%%beginpaths

fill
(51.1663,1.91677) leftjoin
bldmv ( (65.3057,105.222), (0,0), (58.5278,-0.388889) ) .. tension 1 and 1 ..
bldmv ( (163.889,150.305), (0,0), (12,-3) ) .. tension 0.780713 and 2.11326 ..
 {up}(201.083,192) .. tension 1.2515 and 1.5005 ..
 {left}z2 .. tension 4.37336 and 4.30722 ..
 {right}z1 .. tension 2.71544 and 1 ..
 {down}(258.611,226.5) .. tension 1.00284 and 1 ..
 cycle
;
fill
(46.7778,161.139) .. tension 1 and 2.2705 ..
 {right}z1 .. tension 5.38976 and 5.98541 ..
 {left}z2 .. tension 1 and 5.65574 ..
 {down}(104.5,190.667) .. tension 1.28385 and 1.89317 ..
brdmv ( (174.833,129.306), (0,0), (-16.6389,-10.2778) ) .. tension 1 and 1 ..
brdmv ( (227.639,108.028), (0,0), (-59.9167,3.36111) ) setranchor
(303,0) rightjoinii
(241.11,1.94446) .. tension 1 and 1 ..
 {up} cycle
;

%%endpaths
enddefchar;
defchar(fehshape.medi.beforeyeh,-1,-1,-1,-1);
%%backgroundimage:images/qaf_yeh.jpg,-435.447,-944.873,1,0,0,1
%%beginparams
z1 = (260,330);
z2 = (241,226);
z3 = (20,-54);

%%beginverbatim







%%endverbatim

%%beginpaths

fill
(184,28) .. tension 1 and 3.86999 ..
 {left}z3 .. tension 0.942277 and 1.68028 ..
 {up}(1,-40) .. tension atleast 1.42999 ..
(204,114) .. tension 3.13837 and 2.11505 ..
 {up}(288,173) .. tension 2.27443 and 1.11578 ..
 {left}z2 .. tension 4.71418 and 7.77195 ..
 {right}z1 .. tension 1.59002 and 0.911201 ..
 {down}(349,196) .. tension 0.811284 and 3.17615 ..
(313,114) .. tension 1 and 1 ..
 cycle
;
fill
brdmv ( (162,95), (0,0), (39,-60) ) .. tension 1 and 1 ..
 {up}(146,144) .. tension 1 and 1 ..
(190,272) .. tension 1 and 1.58196 ..
 {right}z1 .. tension 2.54056 and 5.6745 ..
 {left}z2 .. tension 1.65835 and 3.60061 ..
 {down}(194,167) .. tension 1.93649 and 1 ..
brdmv ( (202,152), (0,0), (-8,13) ) .. tension 1 and 1 ..
brdmv ( (257,111), (0,0), (20,-21) ) setranchor
(391,0) rightjoinii
brdmv ( (220,31), (103,-32), (40,-30) ) ..
 cycle
;

%%endpaths
%%beginbody


setCursiveAnchor(ltrcursive,z3,ExitAnchor);
enddefchar;
defchar(feh.fina,-1,-1,-1,-1);
%%backgroundimage:images/feh.fina.jpg,-38.0184,-939.263,1,0,0,1
%%beginparams
z1 = (791,364);
z11 = (591,429);
z2 = (765,265);

%%beginverbatim

lefttatweel := lefttatweel - 0.8;

_tatweel := -20 * nuqta;

%%endverbatim

%%beginpaths

fill
bldmvi ( (59,137), (_tatweel,0) ) .. tension 1 and 4.4706 ..
 {right}bldmvi ( (142,303), (_tatweel,0) ) .. tension 1 and 0.75 ..
 {down}bldmvi ( (154,286), (_tatweel,0) ) .. tension 1.49403 and 1 ..
 {down}bldmvi ( (113,184), (_tatweel,0) ) .. tension bldmvi ( 1.14364, 0.7 ) and 1.49652 ..
 {right}bldmvi ( (363,58), (-1389,-100) ) .. tension bldmvi ( 0.75, 0 ) and bldmvi ( 7.23208, -1.1 ) ..
(664,107) .. tension 1 and 3.09654 ..
 {up}(807,190) .. tension 2.05893 and 2.35809 ..
 {left}z2 .. tension 5.95701 and 6.62733 ..
 {right}z1 .. tension 1.95949 and 1 ..
 {down}(870,210) .. tension 1.18594 and 1.42885 ..
(785,85) .. tension 2.527 and 2.527 ..
(746,55) .. tension 8.82087 and 0.75 ..
 {left}bldmvi ( (371,-29), (-1392,-105) ) .. tension 0.878883 and bldmvi ( 1.01539, 0.8 ) ..
 {up} cycle
;
fill
(649,164) .. tension 1 and 2.1057 ..
 {right}z1 .. tension 3.20057 and 6.45091 ..
 {left}z2 .. tension 1.7891 and 1.76858 ..
 {down}(700,195) .. tension 1.06071 and 1 ..
brdmv ( (745,127), (4,7), (-1,-23) ) setranchor
(851,0) rightjoinii
brdmv ( (727,37), (0,0), (-6,-35) ) ..
brdmv ( (687,74), (0,0), (0,-37) ) .. tension 1 and 1 ..
 {up} cycle
;

%%endpaths
%%beginbody
drawcomp(one_dot,identity shifted z11);
enddefchar;
defchar(hah.isol,1581,-1,-1,-1);
%%backgroundimage:images/hah.fina.jpg,-33,-1233,1,0,0,1
%%beginparams
z1 = (593,345);
z2 = (837,-322);

%%beginpaths

fill
(96,-106) .. tension 1.27262 and 1.06096 ..
(143,123) .. tension 1 and 10.5011 ..
 {up}(234,250) .. tension 5.32831 and 1.84291 ..
(186,259) .. tension 1.05028 and 1.66749 ..
 {left}(90,193) .. tension 1 and 1 ..
 {up}(78,210) .. tension 2.51385 and 0.802395 ..
 {right}(210,355) .. tension 8.88517 and 0.75 ..
 {right}(443,341) .. tension 0.75 and 4.05516 ..
 {right}(582,353) .. tension 1 and 1 ..
 {down}z1 .. tension 1 and 1.37031 ..
(545,263) {curl1} .. tension 1.52654 and 1 ..
(266,179) .. tension 0.825647 and 1.11217 ..
 {down}(162,-79) .. tension 1 and 0.917339 ..
 {right}(543,-325) .. tension 0.75 and 2.58661 ..
 {right}(814,-302) .. tension 1 and 0.75 ..
 {down}z2 .. tension 2.12628 and 2.31635 ..
(735,-373) .. tension 3.02226 and 0.902831 ..
 {left}(505,-417) .. tension 0.75 and 1 ..
 {up} cycle
;

%%endpaths
%%beginbody
rightbearing := rightbearing - (x2-x1);
enddefchar;
defchar(hah.isol.ii,-1,-1,-1,-1);
%%backgroundimage:images/jeem.isol.jpg,-83,-1185,1,0,0,1
%%beginparams
z1 = (593,345);
z2 = (864,-304);

%%beginpaths

fill
(109,-120) .. tension 1.27262 and 1.06096 ..
(170,132) .. tension 1 and 10.5011 ..
 {up}(276,251) .. tension 5.32831 and 1.84291 ..
(198,262) .. tension 1.05028 and 1.66749 ..
 {left}(108,182) .. tension 1 and 1 ..
 {up}(100,205) .. tension 2.51385 and 0.802395 ..
 {right}(264,356) .. tension 8.88517 and 0.75 ..
 {right}(455,346) .. tension 0.75 and 4.05516 ..
 {right}(582,353) .. tension 1 and 1 ..
 {down}z1 .. tension 1 and 1.37031 ..
(545,263) {curl1} .. tension 1.07061 and 1 ..
(293,182) .. tension 0.825647 and 1.11217 ..
 {down}(175,-97) .. tension 1 and 0.970199 ..
 {right}(478,-311) .. tension 0.75 and 2.58661 ..
 {right}(830,-282) .. tension 1 and 0.75 ..
 {down}z2 .. tension 2.09281 and 0.75 ..
 {left}(829,-339) .. tension 6.2914 and 3.34684 ..
(601,-388) .. tension 4.77605 and 0.75 ..
 {left}(442,-407) .. tension 0.850755 and 1 ..
 {up} cycle
;

%%endpaths
%%beginbody
rightbearing := rightbearing - (x2-x1);
enddefchar;
defchar(hah.init,-1,-1,-1,-1);
%%backgroundimage:images/hah.init.jpg,-1100,-934,1,0,0,1
%%beginparams
leftVerticalRatio := 10;
leftVerticalRatioNeg := 10;

%%beginverbatim

%lefttatweel := lefttatweel + 0.5;



%%endverbatim

%%beginpaths

fill
bldmv ( (94,8), (51,21), (76,13) ) leftjoin
bldmv ( (226,129), (-4.64668,-2.49084), (-16,-11) ) .. tension 1 and 2.99041 ..
 {up}(241,144) .. tension 17.6157 and 1.40428 ..
 {left}(126,195) .. tension 0.75 and 1.85268 ..
 {left}(44,148) .. tension 0.75 and 1 ..
 {up}(28,157) .. tension 1.74599 ..
(62,223) .. tension 1.6654 ..
 {right}(147,286) .. tension 1.10946 and 0.75 ..
 {right}(478,188) .. tension 1 and 1 ..
 {right}(539,190) .. tension 1 ..
 {down}(550,173) .. tension 3.46819 ..
(507,110) .. tension 3.84859 and 0.75 ..
 {left}(389,106) .. tension 1 ..
(247.106,63.0787) .. tension 1 and 1 ..
 cycle
;

%%endpaths
enddefchar;
defchar(hah.init.ii,-1,-1,-1,-1);
%%backgroundimage:images/jeem_mad.jpg,-1614.33,-1142.33,1,0,0,1
%%beginparams
leftVerticalRatio := 20;
leftVerticalRatioNeg := 10;

%%beginverbatim





%%endverbatim

%%beginpaths

fill
bldmv ( (50,3), (-9,27), (76,13) ) leftjoin
bldmv ( (148,112), (-4.64668,-2.49084), (-16,-11) ) .. tension 1 and 0.874431 ..
 {up}(169,135) .. tension 5.70423 and 1.40428 ..
 {left}(80,178) .. tension 0.75 and 1.85268 ..
 {left}(-42,65) .. tension 0.75 and 1 ..
 {up}(-58,74) .. tension 1.29442 ..
 {right}(109,262) .. tension 1.10946 and 0.75 ..
 {right}(409,162) .. tension 1 and 1 ..
 {right}(470,160) .. tension 1 ..
 {down}(481,143) .. tension 3.46819 ..
(438,80) .. tension 3.84859 and 0.75 ..
 {left}(326,83) .. tension 1 ..
(214,61) .. tension 1 and 1 ..
 cycle
;

%%endpaths
enddefchar;
defchar(hah.init.beforemeem,-1,-1,-1,-1);
%%backgroundimage:images/hah_meem.jpg,-1117,-1152,1,0,0,1
%%beginparams
z1 = (67,167);

%%beginpaths

fill
(56,150) .. tension 0.75 and 1.85096 ..
 {dir hahmeem.dir.1}z1 .. tension 5.96621 and 4.92344 ..
 {up}(212,215) .. tension 8.26438 and 1 ..
 {left}(143,255) .. tension 0.75 and 2.23585 ..
 {left}(44,217) .. tension 1 and 1 ..
 {up}(38,226) .. tension 2.40221 and 0.920336 ..
 {right}(190,338) .. tension 2.2745 and 1 ..
(382,240) .. tension 1 and 1.98627 ..
 {right}(525,211) .. tension 1 and 1 ..
 {down}(537,194) .. tension 3.34991 and 5.82314 ..
 {left}(476,132) .. tension 1.63495 and 1 ..
 {left}(287,157) .. tension 2.20572 and 5.13197 ..
 {left}(82,140) .. tension 1.33992 and 1.42598 ..
 {up} cycle
;

%%endpaths
%%beginbody
leftbearing := -170;
setCursiveAnchor(rtlcursive,z1,ExitAnchorRTL);
enddefchar;
defchar(hah.init.beforeyeh,-1,-1,-1,-1);
%%backgroundimage:images/hah_yeh.jpg,-762,-1091.96,1,0,0,1
%%beginparams
z1 = (-7,-21);
z3 = z1 + (76,83);

%%beginpaths

fill
(-30,9) .. tension 1.33024 and 1 ..
(102,151) .. tension 1 and 16.001 ..
 {up}(238,202) .. tension 3.74612 and 2.03837 ..
 {left}(128,256) .. tension 1.27414 and 2.23585 ..
 {left}(47,207) .. tension 1 and 1 ..
 {up}(35.9466,222.54) .. tension 2.40221 and 1.0188 ..
 {right}(166,338) .. tension 2.04653 and 1 ..
 {right}(482,240) .. tension 1 and 1 ..
 {right}(514,240) .. tension 1 and 1 ..
 {down}(524,229) .. tension 3.34991 and 1.8585 ..
 {left}(475,161) .. tension 1 and 1 ..
 {left}(411,160) .. tension 0.833531 and 1.99657 ..
z3 .. tension 1 and 7.83926 ..
 {left}z1 .. tension 0.75 and 1.47068 ..
 {up} cycle
;

%%endpaths
%%beginbody
leftanchor := z1;
setCursiveAnchor(ltrcursive,z1,ExitAnchor);
enddefchar;
defchar(hah.medi,-1,-1,-1,-1);
%%backgroundimage:images/hah.medi.jpg,-1391.94,-1008.04,1,0,0,1

%%beginverbatim


%%endverbatim

%%beginpaths

fill
bldmv ( (178,31), (-37,14), (76,13) ) leftjoin
bldmv ( (247,156), (-4.64668,-2.49084), (2,-15) ) .. tension 1 and 2.99041 ..
 {up}(262,171) .. tension 17.6157 and 1.40428 ..
 {left}(147,222) .. tension 0.75 and 1.85268 ..
 {left}(65,175) .. tension 0.75 and 1 ..
 {up}(49,184) .. tension 1.74599 ..
(83,250) .. tension 1.6654 ..
 {right}(168,313) .. tension 1.10946 and 0.75 ..
 {right}(499,215) .. tension 1 and 1 ..
 {right}(560,217) .. tension 1 ..
 {down}(571,200) .. tension 3.46819 ..
(528,137) .. tension 3.84859 and 0.75 ..
 {left}(410,133) .. tension 1 ..
(359,120) .. tension 1 and 1 ..
 cycle
;
fill
(452,173) {dir -73.2282} .. tension 0.884422 and 1 ..
 {down}(457,123) .. tension 2.45031 and 0.75 ..
brdmv ( (499,93), (152,-56), (-41,2) ) setranchor
(563,0) rightjoinii
brdmv ( (464,20), (181,-54), (-34,5) ) ..
 {up}(414,103) .. tension 1 and 1.4198 ..
 {dir 87.7485}(414,170) --
 cycle
;

%%endpaths
%%beginbody
%hah.init_(lefttatweel,0);
%tr_ := tr_ shifted (0,-ypart rightanchor);
%%beginbody

enddefchar;
defchar(hah.medi.ii,-1,-1,-1,-1);
%%backgroundimage:images/hah.medi_mad.jpg,-627.616,-961.469,1,0,0,1

%%beginverbatim




%%endverbatim

%%beginpaths

fill
bldmv ( (99,10), (-9,27), (76,13) ) leftjoin
bldmv ( (116,107), (-4.64668,-2.49084), (36,4) ) .. tension 1 and 3.70608 ..
 {up}(176,137) .. tension 5.70423 and 1.40428 ..
 {left}(59,184) .. tension 0.934291 and 3.77863 ..
 {left}(-50,33) .. tension 0.75 and 1 ..
 {up}(-65,42) .. tension 1.29442 ..
 {right}(94,276) .. tension 2.51655 and 0.75 ..
 {right}(381,189) .. tension 0.75 and 0.75 ..
 {right}(479,194) .. tension 0.75 ..
 {down}(489,180) .. tension 1.91912 and 2.17211 ..
(453,115) .. tension 2.95349 and 0.75 ..
 {left}(378,103) .. tension 1 ..
(239,74) .. tension 1 and 1 ..
 cycle
;
fill
(425,151) {dir -76.3522} .. tension 10000 and 0.75 ..
 {down}(428,123) .. tension 0.75 and 0.75 ..
brdmv ( (468,94), (8,-21), (-41,2) ) setranchor
(529,0) rightjoinii
brdmv ( (457,11), (3,-8), (-51,3) ) .. tension 1 and 1.09132 ..
 {up}(390,88) .. tension 0.75 and 10000 ..
 {dir 117.265}(387,148) --
 cycle
;

%%endpaths
%%beginbody

enddefchar;
defchar(hah.medi.afterbeh,-1,-1,-1,-1);
%%backgroundimage:images/behhah.jpg,-1665.24,-1053.77,1,0,0,1
%%beginparams
leftVerticalRatio := 10;
leftVerticalRatioNeg := 10;
z1 = (126,248);

%%beginverbatim


 
lefttatweel := lefttatweel + 0;


%%endverbatim

%%beginpaths

fill
bldmv ( (246,37), (-23.6304,-9.15122), (59.812,14.7619) ) leftjoin
bldmv ( (247,117), (-4.64668,-2.49084), (-38.9551,-11.8222) ) .. tension 1 and 2.99041 ..
 {up}(267,128) .. tension 17.6157 and 1.40428 ..
 {left}(128,160) .. tension 0.75 and 1.21457 ..
 {left}(65,141) .. tension 1.39544 and 1 ..
 {up}(59,154) .. tension 1.74599 ..
(101,227) .. tension 1.6654 ..
 {dir behshape.init.beforehah.dir1}z1 .. tension 1.41572 and 1.64566 ..
 {right}(148,252) .. tension 0.846363 and 2.17862 ..
(299,227) .. tension 1 and 1 ..
 {right}(620,192) .. tension 1 and 1 ..
 {right}(697,192) .. tension 1 ..
 {down}(706,175) .. tension 3.46819 ..
(661,110) .. tension 3.84859 and 0.75 ..
 {left}(510,103) .. tension 1 ..
 cycle
;

%%endpaths
%%beginbody


setCursiveAnchor(rtlcursive,z1, EntryAnchorRTL);

enddefchar;
defchar(hah.medi.afterfeh,-1,-1,-1,-1);
%%beginbody

hah.medi.afterbeh_(lefttatweel,righttatweel);

enddefchar;
defchar(hah.medi.lam_hah,-1,-1,-1,-1);
%%backgroundimage:images/lam_hah.jpg,-1596,-1046,1,0,0,1
%%beginparams
leftVerticalRatio := 10;
leftVerticalRatioNeg := 10;
z1 = (126,248);

%%beginverbatim


 
lefttatweel := lefttatweel + 0;


%%endverbatim

%%beginpaths

fill
bldmv ( (248,37), (-23.6304,-9.15122), (59.812,14.7619) ) leftjoin
bldmv ( (246,118), (-4.64668,-2.49084), (-38.9551,-11.8222) ) .. tension 1 and 2.99041 ..
 {up}(267.206,127.442) .. tension 17.6157 and 1.40428 ..
 {left}(123.329,161.763) .. tension 0.75 and 1.21457 ..
 {left}(63,139) .. tension 1.39544 and 1 ..
 {up}(56,154) .. tension 1.74599 ..
(100.397,226.062) .. tension 1.6654 ..
 {dir behshape.init.beforehah.dir1}z1 .. tension 1.41572 and 1.64566 ..
 {right}(149,251) .. tension 0.846363 and 2.17862 ..
(298.43,226.573) .. tension 1 and 1 ..
 {right}(538,168) .. tension 1 and 1 ..
 {right}(614,168) .. tension 1 ..
 {down}(624,149) .. tension 3.46819 ..
(577,86) .. tension 3.84859 and 0.75 ..
 {left}(428,80) .. tension 1 ..
 cycle
;

%%endpaths
%%beginbody


setCursiveAnchor(rtlcursive,z1, EntryAnchorRTL);
enddefchar;
defchar(hah.medi.aftermeem,-1,-1,-1,-1);
%%beginbody


hah.medi.afterbeh_(lefttatweel,righttatweel);

enddefchar;
defchar(hah.medi.afterbeh.beforeyeh,-1,-1,-1,-1);
%%backgroundimage:images/behhahyeh.jpg,-706.125,-1181.31,1,0,0,1
%%beginparams
z1 = (33,66);
z2 = (150.372,337.395);

%%beginpaths

fill
z1 .. tension 0.945028 and 17.3428 ..
 {up}(251.875,230.273) .. tension 10.0815 and 2.3731 ..
 {left}(132.227,264.569) .. tension 1 and 1 ..
 {left}(96.9943,251.633) .. tension 0.836808 and 1.83749 ..
 {up}(89.9473,259.983) .. tension 2.21464 and 0.752501 ..
 {dir behshape.init.beforehah.dir1}z2 .. tension 1.18822 and 0.860717 ..
 {right}(169.347,341.804) .. tension 2.30186 and 1.05101 ..
 {right}(625.649,254.404) .. tension 1 and 41.5213 ..
 {down}(639.83,249.167) .. tension 1.36745 and 7.49392 ..
 {left}(589.34,176.222) .. tension 1 and 1 ..
 {left}(461.19,186.15) .. tension 1 and 1 ..
(155.982,131.063) .. tension 1 and 24.3399 ..
 {up} cycle
;

%%endpaths
%%beginbody
%%beginbody
leftbearing := 0;
rightbearing := -300;

setCursiveAnchor(ltrcursive,z1,ExitAnchor);
setCursiveAnchor(rtlcursive,z2, EntryAnchorRTL);

enddefchar;
defchar(hah.medi.afterlam.beforeyeh,-1,-1,-1,-1);
%%beginbody

hah.medi.afterbeh.beforeyeh_(0,0);
enddefchar;
defchar(hah.medi.beforeyeh,-1,-1,-1,-1);
%%backgroundimage:images/hah.medi_yeh.jpg,-511,-886,1,0,0,1

%%beginverbatim

righttatweel := righttatweel + 1;

%%endverbatim

%%beginpaths

fill
(427,175) {dir -104.877} .. tension 0.803853 and 1 ..
 {down}(419,131) .. tension 2.45031 and 0.75 ..
brdmv ( (425,107), (152,-56), (-41,2) ) setranchor
(424,6) rightjoinii
brdmv ( (395,15), (124,-56), (-34,5) ) ..
 {up}(367,66) .. tension 1 and 1.31238 ..
 {dir 78.9035}(385,175) --
 cycle
;

%%endpaths
%%beginbody

hah.init.beforeyeh_(charlt,charrt);

setCursiveAnchor(ltrcursive,z1,ExitAnchor);
enddefchar;
defchar(hah.fina,-1,-1,-1,-1);
%%backgroundimage:images/hah.fina.jpg,-33,-1233,1,0,0,1

%%beginverbatim


%%endverbatim

%%beginpaths

fill
(549,308) {dir -117.329} .. tension 0.801974 and 1 ..
 {down}(504,222) .. tension 1 and 0.75 ..
brdmv ( (573,142), (152,-56), (-41,2) ) setranchor
(672,40) rightjoinii
brdmv ( (525,61), (181,-54), (-34,5) ) ..
 {up}(451,166) .. tension 1 and 1.45995 ..
 {dir 68.7611}(478,304) --
 cycle
;

%%endpaths
%%beginbody
hah.isol_(0,0);
tr_ := tr_ shifted (0,-40);
enddefchar;
beginchar(dal.isol,1583,-1,-1,-1);
%%backgroundimage:images/dal.isol.jpg,-312.558,-993.796,1,0,0,1

%%beginpaths

fill
(66,34.8333) .. tension 1 and 1.83466 ..
 {right}(90.3333,90.5) .. tension 1.03809 and 1 ..
 {right}(126.667,81) .. tension 1 and 6.57511 ..
 {up}(286,124) .. tension 1.4561 and 7.6239 ..
 {up}(148,241.167) .. tension 3.32475 and 2.032 ..
 {right}(161.5,324.5) .. tension 1.47023 and 1.19247 ..
 {down}(348.167,129.167) .. tension 0.849554 and 1.9499 ..
(334.667,48.8333) .. tension 3.15796 and 1 ..
 {left}(117,-12.6667) .. tension 0.7731 and 1 ..
 {up} cycle
;

%%endpaths
endchar;
defchar(dal.fina,-1,-1,-1,-1);
%%backgroundimage:images/dal.fina.3.jpg,-1075.16,-1173.94,1,0,0,1
%%beginparams
rightVerticalRatio := 5;

%%beginverbatim

%%endverbatim

%%beginpaths

fill
(110,64) .. tension 1 and 1.70332 ..
 {right}(137,126) .. tension 10.1249 and 0.75 ..
 {right}(199,103) .. tension 1 and 3.36397 ..
 {up}(375,171) .. tension 1.10282 and 1 ..
 {up}(330,360) .. tension 1 and 1.30224 ..
 {right}(362,428) .. tension 5.61548 and 8.32259 ..
brdmv ( (430,213), (10,-32), (53,-198) ) setranchor
(516,0) rightjoinii
(397,100) {dir -116.466} .. tension 1.73439 and 0.75 ..
 {left}(178,6) .. tension 0.885773 and 1 ..
 {up} cycle
;

%%endpaths
%%beginbody
%show rightanchor;
enddefchar;
defchar(dal.fina.afterlam,-1,-1,-1,-1);
%%backgroundimage:images/lam_dal.2.jpg,-1661.11,-1129.17,1,0,0,1
%%beginparams
rightVerticalRatio := 5;

%%beginverbatim

%%endverbatim

%%beginpaths

fill
(135,63) .. tension 1 and 2.70343 ..
 {right}(160,139) .. tension 10.1249 and 0.75 ..
 {right}(207,112) .. tension 1 and 2.45586 ..
 {up}(402,190) .. tension 1.10282 and 1.09782 ..
 {up}(354,372) .. tension 1 and 2.12738 ..
 {right}(382,441) .. tension 5.36892 and 8.32259 ..
brdmv ( (459,216), (10,-32), (63,-256) ) setranchor
(548,-9) rightjoinii
(420,116) {dir -102.367} .. tension 1.83275 and 0.75 ..
 {left}(201,20) .. tension 0.885773 and 1 ..
 {up} cycle
;

%%endpaths
enddefchar;
defchar(reh.isol,1585,-1,-1,-1);
%%backgroundimage:images/reh.isol.jpg,-354,-1103,1,0,0,1

%%beginpaths

fill
(217,188) .. tension 1 and 2.44913 ..
 {right}(238,256) .. tension 1.98804 and 1.0291 ..
 {down}(334,105) .. tension 2.17813 and 0.75 ..
 {left}(77,-183) .. tension 1 and 2.65997 ..
 {up}(-68,-146) .. tension 0.75 and 1 ..
 {right}(-50,-133) .. tension 12.4552 and 0.75 ..
 {right}(25,-134) .. tension 0.985421 and 2.49963 ..
 {up}(285,88) .. tension 1.35044 and 1.69725 ..
 {up} cycle
;

%%endpaths
%%beginbody


enddefchar;
defchar(reh.fina,-1,-1,-1,-1);
%%backgroundimage:images/reh.fina.jpg,-145.402,-1153.07,1,0,0,1

%%beginverbatim

%%endverbatim

%%beginpaths

fill
(-78.5,-199.5) .. tension 1 and 1 ..
 {right}(-59.1667,-186) .. tension 2.92944 and 0.75 ..
 {right}(40.6666,-196.667) .. tension 1.20626 and 1 ..
(235.882,-100.325) .. tension 1 and 1.96358 ..
 {up}(280.863,0.176054) .. tension 2.88036 and 0.914551 ..
 {up}(232.461,57.215) .. tension 1 and 1.64347 ..
 {right}(269.069,125.539) .. tension 1.77596 and 1 ..
(295.814,111.353) .. tension 1.22707 and 1.22707 ..
liii1 ( (333.798,98.7287), (14.6518,-8.83759), (0,0) ) setranchor
(334,0) rightjoinii
liii1 ( (333.888,0.218038), (0.417345,0.208672), (0,0) ) .. tension 1.3584 and 1 ..
 {left}(333.749,0.515546) .. tension 16.2133 and 1 ..
(297.833,-114.667) .. tension 1 and 1 ..
 {left}(114.167,-260.5) .. tension 1.46627 and 1.87503 ..
 {up} cycle
;

%%endpaths
%%beginbody

enddefchar;
defchar(reh.fina.afterbehshape,-1,-1,-1,-1);
%%backgroundimage:images/rehafterbeh.jpg,-327,-1031,1,0,0,1
%%beginparams
z1 = (226.295,240.788);

%%beginverbatim

%%endverbatim

%%beginpaths

fill
z1 .. tension 1.84563 and 1.28405 ..
 {down}(267.163,207.63) .. tension 1.50289 and 0.808354 ..
 {left}(-55,-144) .. tension 0.762382 and 4.06739 ..
 {up}(-250,-102) .. tension 1 and 1 ..
 {right}(-223,-77) .. tension 7.69896 and 0.75 ..
 {right}(-95,-90) .. tension 1.0688 and 2.28212 ..
 {up}(213.756,144.863) .. tension 1.89688 and 1.89688 ..
(183.262,164.444) .. tension 0.880897 and 0.880897 ..
(170.153,208.172) .. tension 0.880897 and 1.14363 ..
 {right}(196.646,249.316) {right} .. tension 0.880897 and 0.880897 ..
 {right} cycle
;

%%endpaths
%%beginbody

setCursiveAnchor(rtlcursive,z1, EntryAnchorRTL);
enddefchar;
defchar(reh.fina.afterseen,-1,-1,-1,-1);
%%backgroundimage:images/seen_medi_reh_fina.jpg,-830,-1091,1,0,0,1
%%beginparams
z1 = (216,54);

%%beginverbatim

%%endverbatim

%%beginpaths

fill
(293,50) {down} .. tension 1.32466 and 1 ..
 {left}(58.7538,-240.875) .. tension 1.21194 and 3.91214 ..
 {up}(-108.5,-188.032) .. tension 1 and 1 ..
 {right}(-79.532,-162.361) .. tension 1.45913 and 0.75 ..
 {right}(-2.18815,-172.946) .. tension 0.849669 and 6.91173 ..
(232.37,-4.10343) {up} .. tension 1.95613 and 0.75 ..
 {up}z1 --
 cycle
;

%%endpaths
%%beginbody

setCursiveAnchor(rtcursii,z1, EntryAnchorRTL);

enddefchar;
defchar(waw.fina,-1,-1,-1,-1);
%%backgroundimage:images/waw.fina.jpg,-598.898,-1124.5,1,0,0,1
%%beginparams
z.mark1 = (321,0);

%%beginpaths

fill
(-45.7222,-184.722) .. tension 1 and 0.75 ..
 {right}(-16.7777,-164.722) .. tension 1.3102 and 0.75 ..
 {right}(53.8889,-169) .. tension 2.79522 and 0.825582 ..
(273.611,-54.1389) .. tension 1 and 2.66942 ..
 {up}(304.818,-0.173696) .. tension 3.89413 and 0.873373 ..
(291.145,1.78584) .. tension 1 and 1.0634 ..
 {up}(168.093,79.2277) .. tension 0.997936 and 1.93819 ..
 {right}(276.326,230.997) .. tension 2.58977 and 0.820856 ..
 {down}(376.917,60.1944) .. tension 1.01953 and 1.56329 ..
 {left}(124,-231.556) .. tension 0.871319 and 3.32248 ..
 {up} cycle
;
fill
(253.425,133.289) .. tension 1 and 3.84864 ..
 {down}(238.204,117.474) .. tension 1 and 2.43661 ..
 {right}(276.086,99.1182) .. tension 4.32986 and 0.75 ..
 {up}(278.719,107.421) .. tension 2.43662 and 1.07348 ..
 {left} cycle
;

%%endpaths
%%beginbody



rightanchor := z.mark1;
enddefchar;
beginchar(waw.isol,1608,-1,-1,-1);
%%backgroundimage:images/waw.isol.jpg,-720,-1095,1,0,0,1
%%beginparams
z1 = (-43.2222,-146.111);
z2 = (200.782,151.574);

%%beginpaths

fill
z1 .. tension 1 and 0.75 ..
 {right}(-18.4444,-122.639) .. tension 1.3102 and 0.75 ..
 {right}(28.6111,-122.056) .. tension 1.39503 and 0.825582 ..
(292.778,-9.27778) .. tension 1 and 2.66942 ..
 {up}(346.316,89.3537) .. tension 1 and 1.80856 ..
 {left}(343,94) .. tension 6.67317 and 0.873373 ..
 {left}(277.213,57.2083) .. tension 1 and 1.37007 ..
 {up}z2 .. tension 0.997936 and 1.93819 ..
 {right}(286.102,296.801) .. tension 2.58977 and 0.820856 ..
 {down}(394,112) .. tension 1.01953 and 1.56329 ..
 {left}(175.111,-174.889) .. tension 0.887877 and 4.85883 ..
 {up} cycle
;
fill
(276.061,199.897) .. tension 1 and 3.84864 ..
 {down}(256.419,175.642) .. tension 1 and 2.43661 ..
 {right}(284.656,151.66) .. tension 4.32986 and 0.75 ..
 {up}(311,168) .. tension 2.43662 and 2.10073 ..
 {left} cycle
;

%%endpaths
%%beginbody

endchar;
beginchar(heh.isol,1607,-1,-1,-1);
%%backgroundimage:images/heh.isol.jpg,-190,-961,1,0,0,1

%%beginpaths

fill
(55,97) .. tension 1.20527 and 0.776444 ..
(80,191) .. tension 0.75 and 5.48944 ..
 {up}(107,239) .. tension 2.06497 and 1.78035 ..
 {up}(105,263) .. tension 8.33879 and 1.36085 ..
 {right}(135,323) .. tension 18.7293 and 0.75 ..
 {down}(295,174) .. tension 0.897732 and 1.31673 ..
 {left}(147,16) .. tension 1.13472 and 1 ..
 {up} cycle
;
fill
(142,218) .. tension 6.22287 and 2.14107 ..
 {down}(113,158) .. tension 1 and 1.12065 ..
 {right}(157,116) .. tension 2.03587 and 1.42726 ..
 {up}(230,146) .. tension 1.36077 and 2.63017 ..
 {left} cycle
;

%%endpaths
endchar;
defchar(heh.shaep.i,-1,-1,-1,-1);
%%backgroundimage:images/heh.init.jpg,-309,-1131,1,0,0,1
%%beginparams
z.heh.shaep.i1 = (107,76);

%%beginverbatim

%%endverbatim

%%beginpaths

fill
z.heh.shaep.i1 .. tension 1 and 1 ..
 {up}(72,143) .. tension 1 and 8.238 ..
 {up}(123,291) .. tension 4.43789 and 0.75 ..
 {up}(110,361) .. tension 1 and 1.0381 ..
 {right}(169,429) .. tension 6.26067 and 1.05547 ..
 {down}(436,139) .. tension 0.817531 and 1.6186 ..
 {left}(353,8) .. tension 1.65052 and 2.92974 ..
 cycle
;
fill
(169,241) .. tension 2.25893 and 1.14592 ..
 {down}(121,170) .. tension 1.45447 and 1 ..
 {right}(172,144) .. tension 0.868507 and 1.46318 ..
 {up}(214,171) .. tension 1.47077 and 1.34136 ..
 {left} cycle
;
fill
(268,241) .. tension 7.85428 and 2.07776 ..
(264,182) .. tension 1.86439 and 3.54194 ..
 {down}(259,134) .. tension 6.50377 and 3.64835 ..
 {right}(367,107) .. tension 1.4814 and 0.967274 ..
 {up}(380,133) .. tension 2.80955 and 5.69699 ..
 {left} cycle
;

%%endpaths
%%beginbody
leftbearing := 0;
tr_ := identity shifted (0,-ypart llcorner currentpicture);
savepicture:=1;
enddefchar;
defchar(heh.shape.ii,-1,-1,-1,-1);
%%backgroundimage:images/heh.init.2.jpg,-413.266,-1016.32,1,0,0,1
%%beginparams
z.heh.shaep.i1 = (234.083,45.4444);

%%beginverbatim

%%endverbatim

%%beginpaths

fill
z.heh.shaep.i1 .. tension 1 and 1 ..
 {up}(68.5278,138.139) .. tension 1 and 8.238 ..
 {up}(118.139,260.444) .. tension 4.43789 and 0.75 ..
(117.639,308.222) .. tension 1 and 1.0381 ..
 {right}(164.139,375.528) .. tension 6.81772 and 1.11113 ..
 {down}(382.528,161.917) .. tension 0.817531 and 1.6186 ..
 {left}(325.917,26.75) .. tension 1.65052 and 2.92974 ..
 cycle
;
fill
(174.556,231.972) .. tension 2.25893 and 1.14592 ..
 {down}(123.778,169.306) .. tension 1.45447 and 1 ..
 {right}(185.194,139.139) .. tension 0.868507 and 1.46318 ..
 {up}(214,156.417) .. tension 1.47077 and 1.34136 ..
 {left} cycle
;
fill
(268,198.639) .. tension 3.33504 and 3.54194 ..
 {down}(259,138.861) .. tension 2.68771 and 3.64835 ..
 {right}(325.795,115.572) .. tension 1.4814 and 0.967274 ..
 {up}(339.028,134.389) .. tension 2.80955 and 5.69699 ..
 {left} cycle
;

%%endpaths
%%beginbody
leftbearing := 0;
tr_ := identity shifted (0,-ypart llcorner currentpicture);
savepicture:=1;
enddefchar;
defchar(heh.init,-1,-1,-1,-1);
%%backgroundimage:images/heh.init.2.jpg,-400.092,-1009.47,1,0,0,1
%%beginparams
z1 = (82,18);

%%beginverbatim



%%endverbatim

%%beginpaths

fill
(159,121) --
(224,57) leftjoin
(116,100) .. tension 1 and 1 ..
 cycle
;

%%endpaths
%%beginbody
draw heh.shape.ii.pic shifted z1;
enddefchar;
defchar(heh.init.beforemeem,-1,-1,-1,-1);
%%backgroundimage:images/heh.medi_meemii.fina.jpg,-138,-1044,1,0,0,1
%%beginparams
z1 = (126,143);
z2 = (-21,132);

%%beginverbatim



%%endverbatim

%%beginpaths

fill
(195,260) --
(247,203) .. tension 1 and 11.6854 ..
(-9,93) {left} .. tension 1.23304 and 0.838429 ..
 {up}(-30,109) .. tension 1 and 1 ..
z2 {dir 35} .. tension 0.976189 and 2.63787 ..
 cycle
;

%%endpaths
%%beginbody
%%endpaths
%%beginbody
draw heh.shaep.i.pic shifted z1;




setCursiveAnchor(hehmeem,z2, ExitAnchor);
leftbearing :=0;
rightbearing  := -0;


enddefchar;
defchar(heh.init.beforeyeh,-1,-1,-1,-1);
%%backgroundimage:images/heh_yeh.jpg,-488,-1031,1,0,0,1
%%beginparams
z1 = (126,143);
z2 = (0,29);
z3 = z2 + (76,83);

%%beginverbatim



%%endverbatim

%%beginpaths

fill
(205,253) --
(254,189) .. tension 1 and 3.46401 ..
z3 .. tension 1.23547 and 3.74703 ..
z2 {left} .. tension 0.75 and 2.16223 ..
 {up}(-67,74) .. tension 1 and 1 ..
(-37,120) .. tension 1 and 2.63787 ..
 cycle
;

%%endpaths
%%beginbody
%%endpaths
%%beginbody
draw heh.shaep.i.pic shifted z1;

setCursiveAnchor(ltrcursive,z2,ExitAnchor);
enddefchar;
defchar(heh.medi,-1,-1,-1,-1);
%%backgroundimage:images/heh.medi.jpg,-594.565,-1127.94,1,0,0,1
%%beginparams
z.mark1 = (190,-299);
z1 = (270,86);

%%beginverbatim




%%endverbatim

%%beginpaths

fill
(110,111) .. tension 7.50675 and 1 ..
(128,179) .. tension 1 and 1.85792 ..
 {right}(256,352) .. tension 4.97132 and 1 ..
 {down}(313,206) .. tension 0.75 and 1.05939 ..
z1 .. tension 1 and 1.82761 ..
 {down}(265,42) .. tension 2.16741 and 1 ..
(302,0) .. tension 0.780826 and 1 ..
 {down}(352,-135) .. tension 0.75 and 1.68374 ..
 {left}(263,-234) .. tension 0.924763 and 2.25827 ..
 {dir 94.1982}(115,-31) {dir -170.581} .. tension 1.2783 and 2.41091 ..
 {left}(63,-40) .. tension 14.7858 and 9.5728 ..
 {left}(72,4) leftjoin
bldmv ( (103,102), (0,0), (7,0) ) ..
 cycle
;
fill
(226,236) .. tension 2.01159 and 7.26942 ..
 {down}(163,140) .. tension 1 and 0.854179 ..
 {right}(170,125) .. tension 2.48174 and 3.34375 ..
 {up}(254,175) .. tension 1.31239 and 1.22629 ..
 {left} cycle
;
fill
(174,-27) {dir -134.254} .. tension 2.49334 and 1.14127 ..
 {right}(267,-134) .. tension 1.1486 and 1.0819 ..
(288,-111) .. tension 2.02546 and 4.55001 ..
 cycle
;

%%endpaths
%%beginbody

%%beginbody


z1 = rightanchor + joinvector;

setMarkAnchor(buttonmark,z.mark1);


enddefchar;
defchar(heh.medi.beforeyeh,-1,-1,-1,-1);

%%beginverbatim



%%endverbatim

%%beginpaths

fill
(403,174) {dir -73.2282} .. tension 0.884422 and 1 ..
 {down}(408,124) .. tension 2.45031 and 0.75 ..
brdmv ( (450,94), (152,-56), (-41,2) ) setranchor
(508,-1) rightjoinii
brdmv ( (415,21), (181,-54), (-34,5) ) ..
 {up}(365,104) .. tension 1 and 1.4198 ..
 {dir 87.7485}(365,171) --
 cycle
;

%%endpaths
%%beginbody

heh.init.beforeyeh_(0,0);
enddefchar;
defchar(heh.fina,-1,-1,-1,-1);
%%backgroundimage:images/heh.fina.jpg,-26.071,-667.965,1,0,0,1
%%beginparams
rightVerticalRatio := 5;

%%beginverbatim




%%endverbatim

%%beginpaths

fill
(110,105) .. tension 1.57845 and 1 ..
(190,224) .. tension 1 and 8.57661 ..
 {up}(296,286) .. tension 0.910087 and 1.98324 ..
 {right}(320,426) .. tension 7.64585 and 1 ..
(382,194) .. tension 1 and 1 ..
brdmv ( (405,140), (47,-16), (-10,-18) ) setranchor
(474,0) rightjoinii
brdmv ( (352,74), (185,-87), (-8,-9) ) .. tension 2.2753 and 2.04588 ..
 {dir brdmv ( 97.9622, 30, 0 )}(334,120) {dir -127.036} .. tension 0.975786 and 1 ..
(291.57,79.377) .. tension 1.13506 and 0.75 ..
 {left}(209,62) .. tension 1 and 2.69002 ..
 {up} cycle
;
fill
(259,148) .. tension 1 and 1 ..
 {up}(326,190) .. tension 3.47055 and 3.93863 ..
 {left}(311,227) .. tension 20.1423 and 3.43297 ..
 {down}(206,169) .. tension 1.68523 and 1 ..
 {right} cycle
;

%%endpaths
enddefchar;
defchar(heh.fina.afterlam,-1,-1,-1,-1);
%%backgroundimage:images/lam_heh.jpg,-78,-1013,1,0,0,1

%%beginverbatim

%%endverbatim

%%beginpaths

fill
(110,105) .. tension 1.57845 and 1 ..
(190,224) .. tension 1 and 8.57661 ..
 {up}(296,286) .. tension 0.910087 and 1.98324 ..
 {right}(320,426) .. tension 7.64585 and 1 ..
(367,238) .. tension 1 and 1 ..
brdmv ( (402,123), (194,-54), (9,-124) ) setranchor
(469,-52) rightjoinii
brdmv ( (352,74), (213,-87), (-19,-16) ) .. tension 2.2753 and 2.04588 ..
 {dir brdmv ( 97.9622, 0, 0 )}(334,120) {dir -127.036} .. tension 0.975786 and 1 ..
(291.57,79.377) .. tension 1.13506 and 0.75 ..
 {left}(209,62) .. tension 1 and 2.69002 ..
 {up} cycle
;
fill
(259,148) .. tension 1 and 1 ..
 {up}(326,190) .. tension 3.47055 and 3.93863 ..
 {left}(311,227) .. tension 20.1423 and 3.43297 ..
 {down}(206,169) .. tension 1.68523 and 1 ..
 {right} cycle
;

%%endpaths
%%beginbody


enddefchar;
defchar(sad.shape.ii,-1,1,-1,-1);
%%backgroundimage:images/sad.isol.jpg,-290.579,-985.015,1,0,0,1
%%beginparams
z.buttonmark = (501,-79);
z1 = (358,0);

%%beginverbatim

z2 = z1 + joinvector;
%%endverbatim

%%beginpaths

fill
(543,282) .. tension 1 and 1 ..
 {down}(680,194) .. tension 1 and 1 ..
(613,64) .. tension 1.72016 and 0.7597 ..
 {left}z1 .. tension 0.75 and 1.98253 ..
 {up}(234,46) .. tension 5.30811 and 2.17119 ..
 {right} cycle
;
fill
(515,194) .. tension 1.56433 and 13.2272 ..
 {down}(354,92) .. tension 1.79471 and 3.95637 ..
 {right}z2 .. tension 10000 and 2.10611 ..
 {up}(605,157) .. tension 2.80169 and 1 ..
 {left} cycle
;

%%endpaths
%%beginbody



setMarkAnchor(buttonmark,z.buttonmark);
enddefchar;
defchar(sad.shape.i,-1,1,-1,-1);
%%backgroundimage:images/sad.init.jpg,-1795.01,-1016.22,1,0,0,1
%%beginparams
z.buttonmark = (502,-89);
z1 = (369,0);

%%beginverbatim

z2 = z1 + joinvector;
%%endverbatim

%%beginpaths

fill
(258,83) .. tension 3.98412 and 1.70972 ..
 {right}(559,272) .. tension 1 and 1 ..
 {down}(681,184) .. tension 1 and 1 ..
(614,54) .. tension 1.72016 and 0.7597 ..
 {left}z1 .. tension 0.75 and 3.66495 ..
 {left}(267,11) .. tension 2.58735 and 2.00876 ..
 {left}(211,-58) .. tension 1 and 1 ..
 {up}(201,-44) .. tension 2.77619 and 1 ..
(213,13) .. tension 1 and 13.08 ..
 cycle
;
fill
(516,184) .. tension 1.56433 and 13.2272 ..
 {down}(371,90) .. tension 1.79471 and 10000 ..
 {right}z2 .. tension 10000 and 2.10611 ..
 {up}(608,139) .. tension 1.4777 and 1 ..
 {left} cycle
;

%%endpaths
%%beginbody

leftbearing := 0;

setMarkAnchor(buttonmark,z.buttonmark);
enddefchar;
defchar(sad.isol,1589,-1,-1,-1);
%%backgroundimage:images/sad.isol.jpg,-287,-979,1,0,0,1
%%beginbody
%%beginbody




sad.shape.ii_(0,0);


pair shift_;
picture pic_;

pic_ := image(
save rightanchor;pair rightanchor;
noonshape.fina_(0,0.5);
show rightanchor,z1;
shift_ := z1 - rightanchor;
%setCursiveAnchor(rtlcursive,z.seenreh shifted shift_, ExitAnchorRTL);
);

draw pic_ shifted shift_;


pair leftanchor;

enddefchar;
defchar(sad.init,-1,-1,-1,-1);
%%backgroundimage:images/sad.init.jpg,-1802.54,-1013.82,1,0,0,1

%%beginverbatim

%%beginparams


%%endverbatim
%%beginbody

behshape.medi.expa.ii_(lefttatweel,0.1);

pair shift_;
picture pic_;

pic_ := image(
sad.shape.i_(0,0);
shift_ :=  rightanchor - z1;
);


draw pic_ shifted shift_;



setMarkAnchor(onedotup,z.onedotup + (200,0));
setMarkAnchor(topmark,z.onedotup + (200,0));

pair rightanchor;

enddefchar;
defchar(sad.init.beforehah,-1,-1,-1,-1);
%%backgroundimage:images/sad_hah.jpg,-821,-848,1,0,0,1

%%beginverbatim

%%beginparams


%%endverbatim
%%beginbody

behshape.medi.expa.ii_(lefttatweel,0.1);

pair shift_;
picture pic_;

pic_ := image(
sad.shape.i_(0,0);
shift_ :=  rightanchor - z1;
);


draw pic_ shifted shift_;



setMarkAnchor(onedotup,z.onedotup + (200,0));
setMarkAnchor(topmark,z.onedotup + (200,0));

pair rightanchor;

enddefchar;
defchar(sad.init.beforereh,-1,-1,-1,-1);
%%backgroundimage:images/sadreh.jpg,-557.18,-991.1,1,0,0,1
%%beginparams
z1 = (-81,54);

%%beginpaths

fill
z1 .. tension 1.23871 and 3.98312 ..
(-55.6106,130.623) .. tension 6.76506 and 2.503 ..
 {right}(147.802,183.415) .. tension 1 and 1 ..
 {down}(167.016,160.1) .. tension 1 and 1 ..
 {down}(166.942,131.1) .. tension 1 and 1 ..
 {right}(210.016,101.1) .. tension 1.71656 and 1 ..
 {right}(455.297,247.1) .. tension 1 and 1 ..
 {down}(590.64,171.1) .. tension 1 and 1 ..
 {left}(313.395,-24.9) .. tension 1 and 1 ..
 {left}(198.504,-17.9) .. tension 2.93381 and 1 ..
 {left}(139.091,-89.9) .. tension 1 and 1 ..
 {up}(120.03,-75.9) .. tension 1 and 1 ..
 {up}(141.996,9.4148) .. tension 3.78729 and 2.35571 ..
 {left}(101.02,76.1) .. tension 1 and 1.57616 ..
 {left}(-39.3692,35.5815) .. tension 1 and 1 ..
 {up} cycle
;
fill
(432.25,151.733) .. tension 1.11066 and 6.69681 ..
 {down}(310.537,82.613) .. tension 1 and 1 ..
 {right}(336.61,73.2133) .. tension 1 and 3.98836 ..
 {up}(502.284,126.647) .. tension 1.9665 and 0.820059 ..
 {left} cycle
;

%%endpaths
%%beginbody

setCursiveAnchor(rtcursii,z1, ExitAnchorRTL);


enddefchar;
defchar(sad.init.beforeyeh,-1,-1,-1,-1);
%%beginbody
sad.shape.ii_(0,0);


pair shift_;
picture pic_;

pic_ := image(
pair tmp_p_;
tmp_p_ = z1;
save rightanchor;pair rightanchor;clearxy;
behshape.medi.beforeyeh_(0,0.5);
show rightanchor;
shift_ := tmp_p_  - rightanchor;
setCursiveAnchor(ltrcursive,z1  shifted shift_,ExitAnchor);
);

draw pic_ shifted shift_;

pair leftanchor, rightanchor;


enddefchar;
defchar(sad.medi,-1,-1,-1,-1);
%%backgroundimage:images/sad.medi.jpg,-1447,-1136,1,0,0,1
%%beginparams
z10 = (584,0);

%%beginverbatim


%%endverbatim

%%beginpaths

fill
(530,90) setranchor
z10 rightjoinii
(431,9) --
 cycle
;

%%endpaths
%%beginbody

begingroup;
clearxy;pair rightanchor;
sad.init_(lefttatweel,0);
endgroup;

rightanchor := z10;

enddefchar;
defchar(sad.medi.beforereh,-1,-1,-1,-1);
%%beginparams
z10 = (584,0);

%%beginpaths

fill
(533,111) setranchor
z10 rightjoinii
(431,9) --
 cycle
;

%%endpaths
%%beginbody

begingroup;
clearxy;pair rightanchor;
sad.init.beforereh_(lefttatweel,0);
endgroup;

rightanchor := z10;

enddefchar;
defchar(sad.medi.beforeyeh,-1,-1,-1,-1);
%%beginparams
z10 = (584,0);

%%beginpaths

fill
(530,90) setranchor
z10 rightjoinii
(431,9) --
 cycle
;

%%endpaths
%%beginbody

begingroup;
pair rightanchor;
sad.init.beforeyeh_(lefttatweel,0);
endgroup;

rightanchor := z10;

enddefchar;
defchar(sad.fina,-1,-1,-1,-1);
%%beginparams
z10 = (584,0);

%%beginpaths

fill
(530,90) setranchor
z10 rightjoinii
(431,9) --
 cycle
;

%%endpaths
%%beginbody

begingroup
pair rightanchor;clearxy;
sad.isol_(lefttatweel,righttatweel);
endgroup;


rightanchor := z10;

enddefchar;
defchar(ain.isol,1593,-1,-1,-1);
%%backgroundimage:images/ain.isol.jpg,-6.4213,-955.523,1,0,0,1
%%beginparams
z1 = (405,279);
z2 = (712,-252);

%%beginpaths

fill
(54,-131) .. tension 0.757824 and 1.77668 ..
 {dir 45.5958}(128,106) {dir 127.377} .. tension 1.7405 and 1 ..
 {up}(17,212) .. tension 1.22521 and 1.27737 ..
 {right}(140,410) .. tension 1 and 1.4189 ..
 {down}(294,353) .. tension 1 and 1 ..
 {left}(276,339) .. tension 2.71859 and 1 ..
 {left}(207,347) .. tension 0.897398 and 2.61311 ..
 {down}(77,273) .. tension 1.44872 and 1.24232 ..
 {right}(211,184) .. tension 2.83586 and 2.54379 ..
 {right}(397,295) .. tension 1 and 1 ..
 {down}z1 .. tension 1 and 1 ..
(382,216) .. tension 1.27146 and 1 ..
(194,85) .. tension 0.93385 and 1.11189 ..
 {down}(115,-126) .. tension 0.996475 and 1.45552 ..
 {right}(369,-282) .. tension 1.04248 and 2.76463 ..
 {right}(694,-229) .. tension 1 and 1 ..
 {down}z2 .. tension 2.9489 and 1 ..
(595,-304) .. tension 1.42387 and 0.75 ..
 {left}(356,-374) .. tension 0.818379 and 0.881882 ..
 {up} cycle
;

%%endpaths
%%beginbody
rightbearing := rightbearing - (x2-x1);
enddefchar;
defchar(ain.init,-1,-1,-1,-1);
%%backgroundimage:images/ain.init.jpg,-1520.73,-983.734,1,0,0,1
%%beginparams
leftVerticalRatioNeg := 10;

%%beginverbatim



%%endverbatim

%%beginpaths

fill
(122,47) .. tension 1.24055 and 1 ..
 {up}(57,178) .. tension 1.73998 and 1.11379 ..
 {right}(235,373) .. tension 0.901607 and 4.12173 ..
 {down}(384,285) .. tension 0.789926 and 1.11772 ..
 {left}(364,263) .. tension 4.45537 and 0.75 ..
 {left}(267,299) .. tension 0.875889 and 6.6797 ..
 {down}(121,225) .. tension 1.80938 and 1 ..
 {right}(292,102) --
 cycle
;
fill
(278,127) .. tension 1 and 6.06567 ..
 {right}(465,196) .. tension 1 and 1 ..
 {down}(468,184) .. tension 5.85262 and 3.75754 ..
 {dir -130.966}(437,114) {dir -138.299} .. tension 1.5104 and 1 ..
(414,101) .. tension 1 and 0.75 ..
(267,45) ..
(133,11) leftjoin
(152,95) ..
 cycle
;

%%endpaths
%%beginbody

enddefchar;
defchar(ain.init.beforeyeh,-1,-1,-1,-1);
%%backgroundimage:images/ain_yeh.jpg,-459.047,-1148.15,1,0,0,1
%%beginparams
z1 = (-45,38);

%%beginverbatim
z3 = z1 + (76,83);

%%endverbatim

%%beginpaths

fill
(229,222) .. tension 1.62366 and 1.0306 ..
 {up}(104,311) .. tension 1.27988 and 1.35218 ..
 {right}(274,521) .. tension 1.12744 and 9.98644 ..
 {down}(407,432) .. tension 1.27169 and 1.72749 ..
 {left}(390,410) .. tension 3.04845 and 1 ..
 {left}(306,446) .. tension 1.27133 and 2.35477 ..
 {down}(166,367) .. tension 1.55055 and 1.10548 ..
 {right}(341,267) --
 cycle
;
fill
(-54,113) .. tension 1 and 1 ..
(392,319) .. tension 2.33663 and 2.33663 ..
 {right}(483,361) .. tension 1 and 1 ..
 {down}(496,343) .. tension 1.81594 and 1.21257 ..
(208,174) .. tension 2.65581 and 5.72084 ..
z3 .. tension 3.36794 and 2.31048 ..
z1 {left} .. tension 1 and 1 ..
 cycle
;

%%endpaths
%%beginbody
leftbearing := 0;

setCursiveAnchor(ltrcursive,z1,ExitAnchor);

enddefchar;
defchar(ain.init.finjani,-1,-1,-1,-1);
%%backgroundimage:images/ain.init.finjani.jpg,-556.231,-875.193,1,0,0,1

%%beginverbatim
leftVerticalRatio:=10;
%%endverbatim

%%beginpaths

fill
(68,5) leftjoin
(96,94) .. tension 1 and 1 ..
(308,183) .. tension 0.75 and 2.97944 ..
 {right}(371,231) .. tension 0.75 and 1 ..
 {down}(391,200) .. tension 1.0975 and 1.87381 ..
(360,142) .. tension 1.67426 and 1 ..
 cycle
;
fill
(56,53) .. tension 2.05219 and 1.07906 ..
 {up}(-21,187) .. tension 1.60659 and 0.955422 ..
 {right}(143,377) .. tension 1 and 3.75866 ..
 {down}(316,291) .. tension 1.78319 and 2.5167 ..
 {left}(298,272) .. tension 1.92488 and 1 ..
 {left}(172,301) .. tension 1 and 3.03694 ..
 {down}(40,243) .. tension 1.26398 and 2.17791 ..
(222,102) --
 cycle
;

%%endpaths
enddefchar;
defchar(ain.medi,-1,-1,-1,-1);
%%backgroundimage:images/ain.medi.jpg,-709.813,-1014.5,1,0,0,1
%%beginparams
z1 = (55,163);
z2 = (320,195);

%%beginverbatim

%%endverbatim

%%beginpaths

fill
bldmv ( (112,16), (-13,15), (18,-14) ) leftjoin
bldmv ( (110,106), (-13,8), (42,-13) ) .. tension 1 and 7.17275 ..
 {right}(238,220) .. tension 1.57103 and 1.20848 ..
 {down}z2 .. tension 2.18347 and 1.12253 ..
 cycle
;
fill
brdmv ( (146,115), (6,15), (0,0) ) .. tension 1 and 1 ..
 {left}z1 .. tension 6.14884 and 2.56634 ..
 {right}(122,250) .. tension 10000 and 3.53521 ..
(144,236) .. tension 1 and 1 ..
brdmv ( (231,134), (19,15), (0,0) ) setranchor
(336,0) rightjoinii
brdmv ( (180,63), (63,30), (-27,12) ) ..
 cycle
;
fill
z1 .. tension 0.75 and 1.48739 ..
 {up}(41,171) .. tension 1.52712 and 1.01546 ..
(92,254) .. tension 1.28267 and 0.75 ..
 {right}(181,280) .. tension 1 and 1 ..
(264,264) .. tension 1 and 1 ..
 {down}z2 .. tension 1.60809 and 1.60897 ..
 {left}(184,151) .. tension 1.59872 and 0.75 ..
 {left} cycle
;

%%endpaths
%%beginbody
show rightanchor;
enddefchar;
defchar(ain.medi.beforeyeh,-1,-1,-1,-1);
%%backgroundimage:images/ain.medi_yeh.jpg,-445,-969,1,0,0,1
%%beginparams
z1 = (55,163);
z2 = (320,195);
z3 = (-68,-43);

%%beginverbatim
z4 = z3 + (76,83);

%%endverbatim

%%beginpaths

fill
bldmv ( (130,79), (-13,15), (18,-14) ) .. tension 1 and 10000 ..
z4 .. tension 10000 and 4.42568 ..
z3 {left} .. tension 2.69934 and 1 ..
 {up}bldmv ( (-94,-4), (-13,8), (42,-13) ) .. tension 2.12507 and 6.06965 ..
 {right}(234,189) .. tension 1.57103 and 1.20848 ..
 {down}z2 .. tension 2.18347 and 1.12253 ..
 cycle
;
fill
brdmv ( (146,115), (6,15), (0,0) ) .. tension 1 and 1 ..
 {left}z1 .. tension 6.14884 and 2.56634 ..
 {right}(122,250) .. tension 10000 and 3.53521 ..
(144,236) .. tension 1 and 1 ..
brdmv ( (231,134), (19,15), (0,0) ) setranchor
(336,-1) rightjoinii
brdmv ( (180,63), (63,30), (-27,12) ) ..
 cycle
;
fill
z1 .. tension 0.75 and 1.48739 ..
 {up}(41,171) .. tension 1.52712 and 1.01546 ..
(92,254) .. tension 1.28267 and 0.75 ..
 {right}(181,280) .. tension 1 and 1 ..
(264,264) .. tension 1 and 1 ..
 {down}z2 .. tension 1.60809 and 1.60809 ..
(181,100) {left} .. tension 1.60897 and 1.60897 ..
 {left}(184,151) .. tension 1.59872 and 0.75 ..
 {left} cycle
;

%%endpaths
%%beginbody
leftbearing := 0;

setCursiveAnchor(ltrcursive,z3,ExitAnchor);
enddefchar;
defchar(ain.fina,-1,-1,-1,-1);
%%backgroundimage:images/ain.fina.jpg,-8.44054,-904.471,1,0,0,1

%%beginverbatim

%%endverbatim

%%beginpaths

fill
(404,-502) .. tension 0.794391 and 0.786982 ..
 {up}(55,-193) .. tension 0.837127 and 24.5236 ..
 {up}(201,120) .. tension 2.67669 and 1.88798 ..
 {left}(113,147) .. tension 1 and 1 ..
 {up}(105,151) .. tension 1.41534 and 1 ..
 {right}(258,265) .. tension 1 and 1.38908 ..
 {down}(390,187) .. tension 0.75 and 3.32415 ..
 {down}brdmv ( (336,117), (14,12), (0,0) ) setranchor
(397,0) rightjoinii
(258,76) {left} .. tension 5.67309 and 0.893446 ..
 {down}(110,-181) .. tension 1 and 0.785103 ..
 {right}(491,-426) .. tension 1 and 4.60106 ..
 {right}(781,-398) .. tension 1 and 1 ..
 {down}(798,-412) .. tension 4.59075 and 1 ..
 {left} cycle
;

%%endpaths
%%beginbody

enddefchar;
defchar(tah.isol,1591,-1,-1,-1);
%%backgroundimage:images/tah.isol.jpg,10.3699,-1115.99,1,0,0,1
%%beginparams
z.mark1 = (708,511);
z1 = (302,-21);

%%beginverbatim


z2 = z1 + joinvector;

%%endverbatim

%%beginpaths

fill
(71,70) .. tension 1 and 1 ..
 {right}(90,88) .. tension 9.94627 and 0.75 ..
(212,71) .. tension 1 and 1.21526 ..
 {right}(317,65) .. tension 17.5873 and 1.90969 ..
 {right}(608,277) .. tension 0.761717 and 2.54062 ..
 {down}(731,197) .. tension 1.19075 and 1 ..
 {left}z1 .. tension 0.912587 and 0.912587 ..
(125,38) .. tension 3.10445 and 3.10445 ..
 {up} cycle
;
fill
(575,202) .. tension 1.98843 and 6.56415 ..
 {left}(374,43) .. tension 1.5517 and 1 ..
 {right}z2 .. tension 0.946512 and 4.02426 ..
 {up}(665,154) .. tension 1.55556 and 1 ..
 {left} cycle
;
fill
(414,126) .. tension 18.59 and 10000 ..
 {up}(339,582) .. tension 2.4198 and 1 ..
 {up}(322,629) .. tension 2.4704 and 2.32184 ..
 {right}(369,745) .. tension 1.01926 and 1 ..
 {down}(385,731) .. tension 1.76904 and 1 ..
(401,643) .. tension 0.75 and 1.00822 ..
 {down}(445,623) .. tension 1.4526 and 2.55197 ..
 {down}(411,546) .. tension 3.81741 and 1.64557 ..
(466,146) --
 cycle
;

%%endpaths
%%beginbody

setMarkAnchor(topmark,z.mark1);
enddefchar;
defchar(tah.init,-1,-1,-1,-1);
%%backgroundimage:images/tah.init.jpg,-1910.5,-1108.5,1,0,0,1

%%beginverbatim


%%endverbatim

%%beginpaths

fill
bldmv ( (154,3), (5,-4), (0,0) ) leftjoin
bldmv ( (146,90), (0,0), (0,0) ) ..
bldmv ( (278,109), (22,24), (0,0) ) .. tension 0.75 and 4.68442 ..
 {up}bldmv ( (426,166), (7,26), (0,0) ) .. tension 3.42809 and 1 ..
 {left}bldmv ( (328,212), (22,24), (0,0) ) .. tension 2.16079 and 1 ..
bldmv ( (131,70), (-25,-22), (0,0) ) --
bldmv ( (78,75), (-20,-29), (0,0) ) .. tension 3.97137 and bldmvi ( 1.8993, -0.2 ) ..
 {right}bldmv ( (365,300), (22,24), (0,0) ) .. tension 0.75 and 1.9428 ..
 {down}bldmv ( (505,221), (22,24), (0,0) ) .. tension 0.974792 and 0.906953 ..
 cycle
;
fill
(180,125) .. tension 1.15287 and 2.27615 ..
 {up}(162,223) .. tension 2.89756 and 1.54613 ..
(122,424) .. tension 1.36479 and 6.42089 ..
(86,608) .. tension 1.76189 and 1.89014 ..
 {up}(62,656) .. tension 2.4704 and 3.9506 ..
 {right}(110,783) .. tension 1.01926 and 1 ..
 {down}(134,759) .. tension 1.76904 and 1 ..
(150,702) .. tension 0.75 and 1.49954 ..
 {down}(173,689) .. tension 0.75 and 1.82087 ..
 {down}(156,604) .. tension 8.031 and 11.2299 ..
 {down}(214,278) .. tension 1.64526 and 7.76985 ..
(220,163) --
 cycle
;

%%endpaths
enddefchar;
defchar(tah.init.beforeyeh,-1,-1,-1,-1);
%%backgroundimage:images/tah.medi_yeh.jpg,-426,-986,1,0,0,1
%%beginparams
z1 = (27,-106);
z2 = (330,6);

%%beginverbatim

z3 = z1 + (76,83);

%%endverbatim

%%beginpaths

fill
z1 .. tension 1.1721 and 1.1721 ..
 {up}(-29,-73) .. tension 1.27329 and 1 ..
(299,93) .. tension 1 and 3.54352 ..
 {up}(552,168) .. tension 3.42809 and 1 ..
 {left}(452,200) .. tension 2.28154 and 7.38854 ..
 {down}(247,46) .. tension atleast 3.58071 ..
 {up}(154,29) .. tension 11.1562 and 3.87537 ..
 {right}(485,288) .. tension 0.75 and 1.9428 ..
 {down}(616,219) .. tension 0.923356 and 1.41156 ..
(519,69) .. tension 1.82326 and 1 ..
z2 .. tension 1 and 3.58346 ..
z3 .. tension 8.62475 and 2.29186 ..
 {left} cycle
;
fill
(258,93) .. tension 1.15287 and 0.956207 ..
 {up}(264,192) .. tension 2.89756 and 1.54613 ..
(244,342) .. tension 1.36479 and 6.42089 ..
(223,507) .. tension 1.76189 and 1.89014 ..
 {up}(205,549) .. tension 2.4704 and 2.09498 ..
 {right}(261,668) .. tension 1.01926 and 0.866448 ..
 {down}(281,645) .. tension 1.76904 and 1 ..
(272,604) .. tension 0.917007 and 1.37458 ..
 {down}(315,567) .. tension 1.48383 and 1.76249 ..
 {down}(288,494) .. tension 8.031 and 1.52358 ..
 {down}(313,290) .. tension 0.858378 and 0.930166 ..
(296,118) --
 cycle
;

%%endpaths
%%beginbody


leftbearing := 0;

setCursiveAnchor(ltrcursive,z1,ExitAnchor);
enddefchar;
defchar(tah.medi,-1,-1,-1,-1);
%%backgroundimage:images/tah.medi.jpg,-1896,-911,1,0,0,1

%%beginverbatim

%%endverbatim

%%beginpaths

fill
(194,92) setranchor
(226,1) rightjoinii
(123,9) .. tension 2.50796 and 3.06571 ..
 cycle
;

%%endpaths
%%beginbody

tah.init_(lefttatweel,righttatweel);


enddefchar;
defchar(tah.medi.beforeyeh,-1,-1,-1,-1);
%%backgroundimage:images/tah.medi_yeh.jpg,-426,-986,1,0,0,1

%%beginverbatim



%%endverbatim

%%beginpaths

fill
(296,9) --
(250,14) --
(287,63) .. tension 1 and 1 ..
(390,84) link
(422.619,0.0681974) .. tension atleast 1 ..
 cycle
;

%%endpaths
%%beginbody


tah.init.beforeyeh_(lefttatweel,righttatweel);
enddefchar;
defchar(tah.fina,-1,-1,-1,-1);

%%beginverbatim


%%endverbatim
%%beginbody


tah.isol_(lefttatweel,righttatweel);

rightanchor := z1;

enddefchar;
defchar(yehshape.fina.ii,-1,-1,-1,-1);
%%backgroundimage:images/fehyeh.jpg,-95,-647.402,1,0,0,1
%%beginparams
z1 = (362,10);
z2 = (597,9);

%%beginverbatim

z3 = z1 + (76,83);

%(497.525,1.20559)
%%endverbatim

%%beginpaths

fill
(22,-36) .. tension 1.15253 and 2.73859 ..
 {right}(123,158) .. tension 1 and 1 ..
 {down}(134.269,138.992) .. tension 2.78482 and 1 ..
 {down}(78.9031,3.93523) .. tension 1 and 0.915494 ..
 {right}(268.641,-112.034) .. tension 1.09661 and 6.40317 ..
 {up}(529.996,-19.7595) .. tension 1.03121 and 1 ..
(497.525,1.20559) .. tension 0.891928 and 0.75 ..
 {left}z1 .. tension 10.1756 and 7.57227 ..
z3 {right} .. tension 1.39519 and 1.43919 ..
(563.648,77.5785) .. tension 1 and 1 ..
 {down}z2 .. tension 1.42107 and 1.14232 ..
 {left}(250,-203) .. tension 0.907684 and 1 ..
 {up} cycle
;

%%endpaths
%%beginbody
rightbearing := x1 - x2;
setCursiveAnchor(ltrcursive,z1,EntryAnchor);
%show rightbearing;
enddefchar;
defchar(yeh.shape.i,-1,-1,-1,-1);
%%backgroundimage:images/yeh.isol.jpg,-38,-1129,1,0,0,1
%%beginparams
z.yeh.shape.i.1 = (405,129);

%%beginverbatim

z.yeh.shape.i.2 = z.yeh.shape.i.1 + (76,83);

%%endverbatim

%%beginpaths

fill
z.yeh.shape.i.1 .. tension 1.23428 and 1 ..
 {up}(330,219) .. tension 1 and 2.19609 ..
 {right}(583.305,511.894) .. tension 1.08196 and 9.18809 ..
 {down}(648,452) .. tension 1.24106 and 6.97322 ..
 {left}(620,375) .. tension 1.63568 and 1 ..
 {left}(558,418) .. tension 2.15632 and 4.90662 ..
 {down}(392,285) .. tension 1 and 0.75 ..
 {right}z.yeh.shape.i.2 .. tension 1.27639 and 1.96365 ..
 {left} cycle
;

%%endpaths
%%beginbody
leftbearing := 0;
enddefchar;
defchar(yeh.shape.ii,-1,-1,-1,-1);
%%backgroundimage:images/yeh.fina.jpg,39.1667,-1042.22,1,0,0,1
%%beginparams
z.yeh.shape.ii.1 = (424,-135);

%%beginverbatim

z.yeh.shape.ii.2 = z.yeh.shape.ii.1 + (76,83);



%%endverbatim

%%beginpaths

fill
z.yeh.shape.ii.1 .. tension 0.972505 and 1 ..
 {up}(394,-82) .. tension 1 and 2.19609 ..
(515,37) link
(732,0) .. tension 10000 and 4.78479 ..
(697,-1) .. tension 1.24106 and 6.97322 ..
 {down}(497,-50) .. tension 0.75 and 2.25721 ..
 {right}z.yeh.shape.ii.2 .. tension 0.75 and 1.96365 ..
 {left} cycle
;

%%endpaths
%%beginbody
leftbearing := 0;
enddefchar;
defchar(alefmaksura.isol,1609,-1,-1,-1);
%%backgroundimage:images/yeh.isol.jpg,-81.194,-1005,1,0,0,1
%%beginbody
yehshape.fina.ii_(0,0);

pair shift_;
picture pic_;

pic_ := image(
yeh.shape.i_(0,0);
shift_ := z1 - z.yeh.shape.i.1;
);

draw pic_ shifted shift_;
rightbearing := 0;

enddefchar;
beginchar(yehshape.fina,-1,-1,-1,-1);
%%backgroundimage:images/yeh.fina.jpg,75,-1047,1,0,0,1
%%beginbody
yehshape.fina.ii_(0,0);

pair shift_;
picture pic_;

pic_ := image(
yeh.shape.ii_(0,righttatweel);
shift_ := z1 - z.yeh.shape.ii.1;
);

draw pic_ shifted shift_;
rightanchor := rightanchor shifted shift_;;
rightbearing := 0;

tr_ := tr_ shifted (0, -ypart rightanchor);

endchar;
defchar(yehshape.isol,1610,-1,-1,-1);
%%beginbody
alefmaksura.isol_(0,0);

enddefchar;
defchar(kaf.isol,1603,-1,-1,-1);
%%backgroundimage:images/kaf.isol.1.jpg,-118.352,-967.865,1,0,0,1

%%beginpaths

fill
(33,21) .. tension 1.17418 and 3.62471 ..
 {right}(63,81) .. tension 2.13621 and 0.75 ..
 {right}(133,68) .. tension 1.3288 and 15.3577 ..
 {up}(587,107) .. tension 5.09844 and 1 ..
(557,346) .. tension 0.75 and 5.58424 ..
 {up}(523,579) .. tension 1 and 1.85313 ..
 {up}(503,630) .. tension 1.36139 and 2.85021 ..
 {right}(561,735) .. tension 2.8009 and 1 ..
(575,651) .. tension 1 and 1 ..
 {down}(613.333,613.333) .. tension 4.95188 and 4.95188 ..
 {down}(594,533) .. tension 13.1647 and 9.07035 ..
 {down}(645,125) .. tension 4.10535 and 1.14023 ..
 {dir -120.931}(614,19) {dir -88.0701} .. tension 19.7294 and 1 ..
 {left}(84,-20) .. tension 1 and 1 ..
 {up} cycle
;
fill
(255,234) .. tension 1.6784 and 1.33888 ..
 {right}(275,252) .. tension 4.85985 and 1.58601 ..
 {up}(353,283) .. tension 2.06098 and 1.23565 ..
 {up}(281,331) .. tension 1 and 2.9092 ..
 {right}(391,496) .. tension 1 and 2.20322 ..
 {down}(399,484) .. tension 2.69063 and 4.2656 ..
 {down}(350,402) .. tension 1.23183 and 1 ..
 {down}(433,348) .. tension 1.06986 and 1.99314 ..
 {left}(331,204) .. tension 1 and 2.03546 ..
 {up} cycle
;

%%endpaths
%%beginbody

enddefchar;
defchar(kaf.init,-1,-1,-1,-1);
%%backgroundimage:images/kaf.init.jpg,-1301.65,-999.902,1,0,0,1

%%beginverbatim

if not known x.kafpos : x.kafpos := 0; fi
if not known y.kafpos : y.kafpos := 0; fi
if not known x.kafpos2 : x.kafpos2 := 0; fi
if not known y.kafpos2 : y.kafpos2 := 0; fi

%%endverbatim

%%beginpaths

fill
((582,792) + z.kafpos) {right} .. tension 0.75 and 1 ..
 {down}((596,771) + z.kafpos) .. tension 1 and 2.54535 ..
((573,708) + z.kafpos) .. tension 9.18768 and 4.65417 ..
 {down}(103,471) .. tension 6.25338 and 0.774053 ..
 {down}(327,120) .. tension 0.857029 and 1 ..
bldmv ( (245,17), (0,0), (2,-8) ) leftjoin
bldmv ( (242,103), (0,0), (11,-5) ) .. tension 1 and 1 ..
 {up}(276,121) .. tension 1.67402 and 5.60646 ..
(226,229) .. tension 2.28057 and 1.0258 ..
(125,326) .. tension 2.52601 and 1.16312 ..
 {up}(32,387) .. tension 1 and 1.21903 ..
((100,555) + z.kafpos2) .. tension 1.59171 and 6.74681 ..
 cycle
;

%%endpaths
%%beginbody

rightbearing := -200; 

enddefchar;
defchar(kaf.init.ii,-1,-1,-1,-1);
%%backgroundimage:images/kaf.init.ii.jpg,-1195.68,-1011,1,0,0,1
%%beginparams
leftVerticalRatio := 10;
leftVerticalRatioNeg := 10;

%%beginverbatim



numeric _tatweel;
_tatweel := 20 * nuqta;
%%endverbatim

%%beginpaths

fill
(1320,85) .. tension 5.21499 and 2.20804 ..
(1018,58) .. tension 4.79831 and 4.79831 ..
bldmv ( (316,7), (103,-49), (95,10) ) leftjoin
bldmv ( (398,95), (47,-49), (72,11) ) .. tension 1 and 1 ..
(1020,141) .. tension 1 and 8.38318 ..
 {up}(1304,173) .. tension 1.79167 and 1.32758 ..
 {left}(1201,242) .. tension 6.7667 and 1 ..
 {left}(195,180) .. tension 1.31763 and 0.909914 ..
 {up}(29,244) .. tension 1.47306 and 1.21903 ..
(162,453) .. tension 1.59171 and 1.88264 ..
 {right}(467,609) .. tension 1.99444 and 6.32225 ..
 {left}(429,531) .. tension 5.20633 and 1 ..
(243,443) .. tension 1 and 2.98033 ..
 {down}(93,300) .. tension 4.01491 and 0.75 ..
 {right}(237,261) .. tension 0.75 and 4.14509 ..
 {right}(1259,328) .. tension 1.40423 and 1.28104 ..
 {down}(1382,190) .. tension 1.45818 and 2.68873 ..
 cycle
;

%%endpaths
%%beginbody



enddefchar;
defchar(kaf.init.ii.i,-1,-1,-1,-1);
%%backgroundimage:images/kaf.init.ii.i.jpg,-1986.73,-1060.74,1,0,0,1
%%beginparams
leftVerticalRatio := 100;
leftVerticalRatioNeg := 100;
z.mark1 = bldmvi ( (1005,653), (-830,-2) );
z.mark2 = bldmvi ( (713,386), (-830,-2) );

%%beginverbatim


lefttatweel := lefttatweel - 5;

%%endverbatim

%%beginpaths

fill
(1763,115) .. tension 5.21499 and 2.20804 ..
bldmvi ( (1377,72), (-199,-9) ) .. tension 4.79831 and 4.79831 ..
bldmvi ( (648,16), (-516,-6) ) leftjoin
bldmvi ( (677,101), (-480,-6) ) .. tension 1 and 1 ..
bldmvi ( (1424,166), (-199,-13) ) .. tension 1 and 13.8373 ..
 {up}(1747,203) .. tension 1.79167 and 1.32758 ..
 {left}(1647,270) .. tension 2.77908 and 1 ..
bldmvi ( (1405,246), (-71,-5) ) .. tension 1 and 1 ..
 {left}bldmvi ( bldmvi ( (551,215), (-828,-2) ), (46,-11) ) .. tension 1.31763 and 3.0911 ..
 {up}bldmvi ( (241,261), (-828,-2) ) .. tension 1.47306 and 1.21903 ..
bldmvi ( (381,454), (-828,-2) ) .. tension 1.59171 and 1.88264 ..
 {right}bldmvi ( (850,666), (-828,-2) ) .. tension 1.99444 and 6.32225 ..
 {left}bldmvi ( (817,571), (-828,-2) ) .. tension 5.20633 and 1 ..
bldmvi ( (469,428), (-828,-2) ) .. tension 1 and 2.98033 ..
 {down}bldmvi ( (336,323), (-828,-2) ) .. tension 8.16313 and 1 ..
 {right}bldmvi ( (668,299), (-748,-15) ) .. tension 2.99705 and 1 ..
bldmvi ( (1454,331), (-84,-5) ) .. tension 4.14509 and 4.14509 ..
 {right}(1696,360) .. tension 1.40423 and 1.28104 ..
 {down}(1843,223) .. tension 1.45818 and 2.68873 ..
 cycle
;

%%endpaths
%%beginbody

tr_ := tr_ shifted (0, -ypart leftanchor);

defAnchor(topmarks,z.mark1,MarkAnchor);
defAnchor(smallletters,z.mark2,MarkAnchor);

enddefchar;
defchar(kaf.init.iii,-1,-1,-1,-1);
%%beginbody

z.kafpos = (-200,100);
z.kafpos2 = (-20,-0);
kaf.init_(lefttatweel,righttatweel);

rightbearing := 50; 

enddefchar;
defchar(kaf.init.beforelam,-1,-1,-1,-1);
%%backgroundimage:images/kaf_lam.jpg,-594.97,-1045.07,1,0,0,1
%%beginparams
z4 = (-72.9696,364.074);

%%beginverbatim

if not known x.kafpos : x.kafpos := 0; fi
if not known y.kafpos : y.kafpos := 0; fi

%%endverbatim

%%beginpaths

fill
((382.454,727.058) + z.kafpos) {right} .. tension 0.75 and 1 ..
 {down}((392.454,711.058) + z.kafpos) .. tension 1 and 2.54535 ..
((369.454,635.058) + z.kafpos) .. tension 9.18768 and 6.92449 ..
 {down}z4 .. tension 8.85555 and 0.75 ..
 {down}(183.03,153.074) .. tension 0.857029 and 1 ..
bldmv ( (114.03,23.0736), (0,0), (2,-8) ) leftjoin
bldmv ( (108.03,105.074), (0,0), (11,-5) ) .. tension 1 and 1 ..
 {up}(131.03,142.074) .. tension 1.67402 and 6.04181 ..
(-122.97,275.074) .. tension 2.28057 and 0.75 ..
 {up}(-143.97,349.074) .. tension 2.43753 and 111.847 ..
 cycle
;

%%endpaths
%%beginbody
rightbearing := -100; 

enddefchar;
defchar(kaf.init.iv,-1,-1,-1,-1);
%%backgroundimage:images/kaf.init.jpg,-1301.65,-999.902,1,0,0,1

%%beginverbatim

if not known x.kafpos : x.kafpos := 0; fi
if not known y.kafpos : y.kafpos := 0; fi
if not known x.kafpos2 : x.kafpos2 := 0; fi
if not known y.kafpos2 : y.kafpos2 := 0; fi

%%endverbatim

%%beginpaths

fill
((456,838) + z.kafpos) {right} .. tension 0.75 and 1 ..
 {down}((470,817) + z.kafpos) .. tension 1 and 2.54535 ..
((447,754) + z.kafpos) .. tension 9.18768 and 4.65417 ..
 {down}(103,471) .. tension 6.25338 and 0.774053 ..
 {down}(327,120) .. tension 0.857029 and 1 ..
bldmv ( (245,17), (0,0), (2,-8) ) leftjoin
bldmv ( (242,103), (0,0), (11,-5) ) .. tension 1 and 1 ..
 {up}(276,121) .. tension 1.67402 and 5.60646 ..
(226,229) .. tension 2.28057 and 1.0258 ..
(125,326) .. tension 2.52601 and 1.16312 ..
 {up}(32,387) .. tension 1 and 1.21903 ..
((100,555) + z.kafpos2) .. tension 1.59171 and 6.74681 ..
 cycle
;

%%endpaths
%%beginbody

rightbearing := -50; 

enddefchar;
defchar(kaf.init.beforelam.ii,-1,-1,-1,-1);
%%backgroundimage:images/kaf_lam.jpg,-624,-1043,1,0,0,1
%%beginparams
z4 = (-102,362);

%%beginverbatim

if not known x.kafpos : x.kafpos := 0; fi
if not known y.kafpos : y.kafpos := 0; fi

%%endverbatim

%%beginpaths

fill
((245,741) + z.kafpos) {right} .. tension 0.75 and 1 ..
 {down}((255,725) + z.kafpos) .. tension 1 and 2.54535 ..
((232,649) + z.kafpos) .. tension 9.18768 and 6.92449 ..
 {down}z4 .. tension 8.85555 and 0.75 ..
 {down}(154,151) .. tension 0.857029 and 1 ..
bldmv ( (85,21), (0,0), (2,-8) ) leftjoin
bldmv ( (79,103), (0,0), (11,-5) ) .. tension 1 and 1 ..
 {up}(102,140) .. tension 1.67402 and 6.04181 ..
(-152,273) .. tension 2.28057 and 0.75 ..
 {up}(-173,347) .. tension 2.43753 and 111.847 ..
 cycle
;

%%endpaths
%%beginbody
rightbearing := -100; 

enddefchar;
defchar(kaf.init.beforeyeh,-1,-1,-1,-1);
%%backgroundimage:images/Kaf_yeh.jpg,-292,-1045,1,0,0,1
%%beginparams
z1 = (163,66);

%%beginverbatim
z3 = z1 + (76,83);
%%endverbatim

%%beginpaths

fill
z3 .. tension 1.25372 and 2.45734 ..
 {left}z1 .. tension 1 and 2.01759 ..
 {up}(96,110) .. tension 1.54555 and 3.15829 ..
 {up}(232,229) .. tension 1.35748 and 14.3601 ..
 {left}(96,425) .. tension 1.09635 and 1 ..
 {up}(2,498) .. tension 1 and 1.21903 ..
(62,684) .. tension 1.59171 and 0.910654 ..
(295,824) .. tension 1.8592 and 5.60943 ..
 {right}(595,952) .. tension 2.83286 and 3.83917 ..
 {dir -126.703}(569,873) .. tension 6.92833 and 1 ..
(292,733) .. tension 0.913449 and 2.54535 ..
 {down}(62,586) .. tension 9.18768 and 1 ..
(130,530) .. tension 6.25338 and 0.774053 ..
 {down}(286,269) .. tension 0.78659 and 10000 ..
 cycle
;

%%endpaths
%%beginbody
leftbearing := 0;

setCursiveAnchor(ltrcursive,z1,ExitAnchor);

rightbearing := -250;

enddefchar;
defchar(kaf.medi,-1,-1,-1,-1);
%%backgroundimage:images/kaf.medi.jpg,-531.76,-1243.6,1,0,0,1
%%beginparams
z4 = (-4,503);

%%beginverbatim

minRight := -2;

%%endverbatim

%%beginpaths

fill
(2,609) .. tension 1.68637 and 24.1761 ..
 {right}(537,856) .. tension 0.75 and 1 ..
 {down}(553,838) .. tension 1 and 2.54535 ..
(522,765) .. tension 9.18768 and 4.3056 ..
 {down}z4 .. tension 8.85555 and 0.75 ..
 {down}(236,126) .. tension 0.857029 and 1 ..
bldmv ( (147,23), (0,0), (9,-16) ) leftjoin
bldmv ( (138,118), (0,0), (28,-7) ) .. tension 1 and 1 ..
 {up}(175,155) .. tension 1.67402 and 6.04181 ..
(16,350) .. tension 2.28057 and 0.75 ..
 {up}(-56,466) .. tension 1.59828 and 1.21903 ..
 cycle
;
fill
(150,293) .. tension 1 and 10000 ..
z4 {right} .. tension 10000 and 1 ..
brdmv ( (130,393), (0,0), (-8,-8) ) .. tension 1 and 1 ..
brdmv ( (310,260), (41,2), (-29,-34) ) ..
brdmv ( (572,107), (333,-59), (-156,-8) ) setranchor
(675,0) rightjoinii
brdmv ( (577,13), (476,-103), (-176,-2) ) ..
brdmv ( (356,138), (7,4), (-61,-47) ) .. tension 1 and 1 ..
 cycle
;

%%endpaths
enddefchar;
defchar(kaf.medi.beforemeem,-1,-1,-1,-1);
%%backgroundimage:images/kaf.medi_meem.jpg,-207,-1079,1,0,0,1
%%beginparams
z1 = (243,70);
z4 = (187,454);

%%beginverbatim

minRight := -2;

%%endverbatim

%%beginpaths

fill
(208,570) .. tension 1.68637 and 24.1761 ..
 {right}(603,784) .. tension 0.75 and 1 ..
 {down}(619,766) .. tension 1 and 2.54535 ..
(588,693) .. tension 9.18768 and 4.3056 ..
 {down}z4 .. tension 8.85555 and 0.75 ..
 {down}(332,159) .. tension 0.857029 and 4.27751 ..
 {left}bldmv ( (252,31), (0,0), (9,-16) ) ..
 {up}bldmv ( (188,89), (0,0), (28,-7) ) .. tension 1 and 1 ..
 {up}(282,148) .. tension 1.67402 and 6.04181 ..
(217,284) .. tension 2.28057 and 0.75 ..
 {up}(135,415) .. tension 1.59828 and 1.21903 ..
 cycle
;
fill
(225,340) .. tension 1 and 7.01714 ..
z4 {right} .. tension 12.9016 and 1 ..
brdmv ( (267,376), (0,0), (-8,-8) ) .. tension 1 and 1 ..
brdmv ( (413,242), (41,2), (-29,-34) ) ..
brdmv ( (586,116), (333,-59), (-156,-8) ) setranchor
(675,3) rightjoinii
brdmv ( (537,37), (476,-103), (-176,-2) ) ..
brdmv ( (315,229), (7,4), (-61,-47) ) .. tension 1 and 1 ..
 cycle
;

%%endpaths
%%beginbody

setCursiveAnchor(kafmeem,z1, EntryAnchor);

enddefchar;
defchar(kaf.medi.beforeyeh,-1,-1,-1,-1);
%%backgroundimage:images/kaf.medi_yeh.jpg,-347,-1101,1,0,0,1
%%beginparams
z1 = (186,-44);
z4 = (21,489);

%%beginverbatim

z3 = z1 + (76,83);

minRight := -2;

%%endverbatim

%%beginpaths

fill
(51,603) .. tension 1.68637 and 24.1761 ..
 {right}(614,870) .. tension 0.75 and 1 ..
 {down}(635,849) .. tension 1 and 2.54535 ..
(607,787) .. tension 9.18768 and 4.3056 ..
 {down}z4 .. tension 8.85555 and 0.75 ..
 {down}(282,137) .. tension 0.857029 and 4.27751 ..
z3 ..
 {left}bldmv ( z1, (0,0), (9,-16) ) ..
 {up}bldmv ( (95,-4), (0,0), (28,-7) ) .. tension 1.34044 and 1 ..
 {up}(224,142) .. tension 1.67402 and 6.04181 ..
(64,342) .. tension 2.28057 and 0.75 ..
 {up}(-34,467) .. tension 1.59828 and 1.21903 ..
 cycle
;
fill
(167,314) .. tension 1 and 7.01714 ..
z4 {right} .. tension 12.9016 and 1 ..
brdmv ( (238,337), (0,0), (-7,-18) ) .. tension 1 and 1 ..
brdmv ( (422,203), (41,2), (-41,-65) ) ..
brdmv ( (587,104), (333,-59), (-156,-8) ) setranchor
(675,3) rightjoinii
brdmv ( (533,26), (476,-103), (-175,7) ) ..
brdmv ( (297,202), (7,4), (-45,-25) ) .. tension 1 and 1 ..
 cycle
;

%%endpaths
%%beginbody


leftbearing:= 0;

setCursiveAnchor(ltrcursive,z1,ExitAnchor);

enddefchar;
defchar(kaf.medi.beforelam,-1,-1,-1,-1);
%%backgroundimage:images/kaf.medi_lam.jpg,-1169.09,-1227.17,1,0,0,1

%%beginverbatim



kaf.init.beforelam_(lefttatweel,0);



picture pic_;
pic_ :=  currentpicture;
currentpicture:=nullpicture;

pair dir_;

dir_ := diratpoint z4 of (pathpart pic_);


%%endverbatim

%%beginpaths

fill
(-78,315) .. tension 1 and 1.79826 ..
z4 {right} .. tension 10000 and 1 ..
(45,325) .. tension 1 and 1 ..
(222,204) ..
brdmv ( (329,109), (302,-80), (-56,-12) ) setranchor
(393,-1) rightjoinii
brdmv ( (313,13), (475,-112), (-56,-6) ) ..
(205,123) .. tension 1 and 1 ..
(101,219) .. tension 1 and 1 ..
 cycle
;

%%endpaths
%%beginbody

addto currentpicture also pic_;
enddefchar;
defchar(kaf.fina,-1,-1,-1,-1);
%%backgroundimage:images/kaf.fina.jpg,-52.3056,-1113,1,0,0,1
%%beginparams
rightVerticalRatio := 5;

%%beginverbatim



%%endverbatim

%%beginpaths

fill
(23,157) .. tension 0.951748 and 8.89073 ..
 {right}(115,322) .. tension 1 and 1 ..
 {down}(125,302) .. tension 1 and 1.62263 ..
 {down}(90,207) .. tension 1 and 0.914803 ..
 {right}(279,67) .. tension 0.810168 and 3.22513 ..
 {up}(642,195) .. tension 5.82038 and 2.64594 ..
 {up}(589,654) .. tension 2.30568 and 4.5919 ..
 {right}(624,713) .. tension 3.66496 and 1.87371 ..
(667,517) .. tension 1 and brdmvi ( 9.90405, 2 ) ..
(717,176) setranchor
(809,-1) rightjoinii
(658,116) {dir -127.628} .. tension 3.58671 and 1 ..
(569,50) .. tension 1.31527 and 1 ..
 {left}(269,-20) .. tension 0.75 and 1.81337 ..
 {up} cycle
;
fill
(233,271) .. tension 1.6784 and 1.33888 ..
 {right}(243,288) .. tension 4.85985 and 0.75 ..
 {right}(316,268) .. tension 1.49002 and 3.05366 ..
 {up}(403,303) .. tension 6.51809 and 0.896193 ..
 {up}(289,367) .. tension 1.25921 and 2.02954 ..
 {right}(400,515) .. tension 1 and 2.20322 ..
 {down}(432,492) .. tension 2.69063 and 1.03732 ..
(381,429) .. tension 2.46845 and 1.44632 ..
 {down}(358,416) .. tension 1.47561 and 0.948091 ..
 {down}(478,355) .. tension 1.16642 and 1.25532 ..
 {left}(373,214) .. tension 1 and 2.03546 ..
 {up} cycle
;

%%endpaths
enddefchar;
defchar(kaf.medi.beforelam.ii,-1,-1,-1,-1);
%%beginbody

z.kafpos = (-120,120);
kaf.medi.beforelam_(lefttatweel,righttatweel);
enddefchar;
defchar(kaf.fina.afterlam,-1,-1,-1,-1);
%%backgroundimage:images/lam_kaf.fina.jpg,-45.8,-972.6,1,0,0,1
%%beginparams
rightVerticalRatio := 5;

%%beginverbatim



%%endverbatim

%%beginpaths

fill
(-9,195) .. tension 0.951748 and 8.89073 ..
 {right}(83,350) .. tension 1 and 1 ..
 {down}(91,332) .. tension 1 and 1.62263 ..
 {down}(54,230) .. tension 1 and 0.914803 ..
 {right}(268,88) .. tension 0.810168 and 5.1145 ..
 {up}(627,196) .. tension 5.82038 and 2.64594 ..
 {up}(566,580) .. tension 2.30568 and 1.45846 ..
 {right}(604,643) .. tension 2.69298 and 1.87371 ..
(644,496) .. tension 1 and brdmvi ( 9.90405, 2 ) ..
(696,184) setranchor
(786,-58) rightjoinii
(637,128) {dir -122.132} .. tension 1.10904 and 1 ..
(543,51) .. tension 1.31527 and 1 ..
 {left}(246,-6) .. tension 0.75 and 1.24482 ..
 {up} cycle
;
fill
(235,279) .. tension 1.6784 and 1.33888 ..
 {right}(244,291) .. tension 4.85985 and 0.75 ..
 {right}(328,284) .. tension 1.49002 and 3.05366 ..
 {up}(415,319) .. tension 6.51809 and 0.896193 ..
 {up}(301,383) .. tension 1.25921 and 2.02954 ..
 {right}(418,547) .. tension 1 and 2.20322 ..
 {down}(447,527) .. tension 1.46215 and 1.03732 ..
(403,475) .. tension 2.46845 and 1.44632 ..
 {down}(368,445) .. tension 1.47561 and 0.948091 ..
 {down}(490,371) .. tension 1.45331 and 1.44595 ..
 {left}(396,231) .. tension 1 and 3.10897 ..
 {up} cycle
;

%%endpaths
enddefchar;
defchar(kaf.medi.ii,-1,-1,-1,-1);
%%backgroundimage:images/kafii.medi.jpg,-614.127,-899.413,1,0,0,1

%%beginverbatim
%lefttatweel := lefttatweel + 1;
%%endverbatim

%%beginpaths

fill
(1205,117) .. tension 5.21499 and 2.20804 ..
(1046,100) .. tension 4.79831 and 4.79831 ..
(713,52) .. tension 0.75 and 0.75 ..
bldmv ( (320,8), (-485,-102), (1,0) ) leftjoin
bldmv ( (336,98), (-489,-96), (38,0) ) .. tension 1 and 1 ..
(783,151) .. tension 2.24587 and 2.24587 ..
(1058,189) .. tension 1 and 8.38318 ..
 {up}(1190,204) .. tension 1.79167 and 1.32758 ..
 {left}(1080,263) .. tension 6.7667 and 1 ..
 {left}(195,180) .. tension 1.31763 and 0.909914 ..
 {up}(29,244) .. tension 1.47306 and 1.21903 ..
(162,453) .. tension 1.59171 and 1.88264 ..
 {right}(467,609) .. tension 1.99444 and 6.32225 ..
 {left}(429,531) .. tension 5.20633 and 1 ..
(243,443) .. tension 1 and 2.98033 ..
 {down}(93,300) .. tension 4.01491 and 0.75 ..
 {right}(237,261) .. tension 1.02656 and 4.14509 ..
 {right}(1111,344) .. tension 1.40423 and 1.28104 ..
 {down}(1267,242) .. tension 1.45818 and 2.68873 ..
 cycle
;
fill
(1134,143) {dir -71.3871} ..
(1172,100) setranchor
(1305,0) rightjoinii
(1126,38) ..
 {dir 88.8918}(1094,139) --
 cycle
;

%%endpaths
%%beginbody



%show leftanchor;
%show rightanchor;


enddefchar;
defchar(kaf.medi.ii.i,-1,-1,-1,-1);
%%backgroundimage:images/kaf.medi.ii.i.jpg,-1468.13,-1008.53,1,0,0,1

%%beginverbatim

%lefttatweel := lefttatweel ;


%%endverbatim

%%beginpaths

fill
(1669,161) {dir -71.3871} ..
(1715,114) setranchor
(1833,5) rightjoinii
(1658,62) ..
 {dir 88.8918}(1614,154) --
 cycle
;

%%endpaths
%%beginbody


kaf.init.ii.i_(lefttatweel,0);



defAnchor(topmarks,z.mark1,MarkAnchor);



enddefchar;
beginchar(zeroindic,1632,-1,-1,-1);
%%backgroundimage:images/20.jpg,-572.648,-1273.51,1,0,0,1

%%beginpaths

fill
(112,326) .. tension 1.54346 and 2.12931 ..
 {right}(157,393) .. tension 1 and 3.51889 ..
(221,350) .. tension 2.77152 and 2.22962 ..
 {left}(177,283) .. tension 1.05601 and 4.53746 ..
 {up} cycle
;

%%endpaths
%%beginbody

leftbearing := 0;
rightbearing := 0;
currentpicture := currentpicture scaled digitscale;

tr_ := tr_ shifted (0,-ypart llcorner currentpicture + 95) ;

savepicture:=1;

endchar;
beginchar(oneindic,1633,-1,-1,-1);
%%backgroundimage:images/174.jpg,-1677,-1108,1,0,0,1

%%beginpaths

fill
(-12,376) .. tension 1.39326 and 3.56267 ..
 {right}(18,443) .. tension 3.47588 and 1 ..
(109,261) .. tension 1 and 1 ..
 {down}(126,139) .. tension 1 and 1.88622 ..
 {left}(98,84) .. tension 0.997901 and 1.29754 ..
 {up}(84,98) .. tension 2.36163 and 1.16067 ..
(43,256) .. tension 1 and 9.19243 ..
 {up} cycle
;

%%endpaths
%%beginbody

leftbearing := 0;
rightbearing := 0;
currentpicture := currentpicture scaled digitscale;
tr_ := tr_ shifted (0,-ypart llcorner currentpicture);
savepicture:=1;
endchar;
beginchar(twoindic,1634,-1,-1,-1);
%%backgroundimage:images/20.jpg,-436.279,-1086.51,1,0,0,1

%%beginpaths

fill
(-3,254) .. tension 1 and 0.888633 ..
 {right}(111,363) .. tension 1.60936 and 7.83212 ..
(179,349) .. tension 3.10443 and 2.06047 ..
(162,279) .. tension 2.9275 and 2.91666 ..
 {down}(52,279) .. tension 5.45053 and 0.75 ..
 {down}(110,67) .. tension 1 and 1.63383 ..
 {left}(86,0) .. tension 1.68939 and 0.755454 ..
(63,71) .. tension 1 and 1.18746 ..
 {up} cycle
;

%%endpaths
%%beginbody


leftbearing := 0;
rightbearing := 0;
currentpicture := currentpicture scaled digitscale;
tr_ := tr_ shifted (0,-ypart llcorner currentpicture);
savepicture:=1;
endchar;
beginchar(threeindic,1635,-1,-1,-1);
%%backgroundimage:images/34.jpg,-423.767,-991,1,0,0,1

%%beginpaths

fill
(34,304) .. tension 1.5355 and 1.35491 ..
 {right}(59,371) .. tension 1.83967 and 1 ..
 {right}(129,305) .. tension 0.75 and 1 ..
 {right}(192,366) .. tension 1.25359 and 1 ..
 {right}(232,319) .. tension 1.02439 and 1.2027 ..
 {right}(289,370) .. tension 0.90042 and 4.43896 ..
 {down}(300,339) .. tension 1.84503 and 1.1337 ..
 {left}(231,238) .. tension 1 and 1 ..
 {left}(188,245) .. tension 1.46964 and 1.8738 ..
 {down}(145,205) .. tension 4.36232 and 0.75 ..
 {down}(165,81) .. tension 1 and 1.96399 ..
 {left}(143.056,3.47222) .. tension 2.82402 and 1 ..
(98.6111,156.944) .. tension 1.42322 and 1.89974 ..
 {up} cycle
;

%%endpaths
%%beginbody

leftbearing := 0;
rightbearing := 0;
currentpicture := currentpicture scaled digitscale;
tr_ := tr_ shifted (0,-ypart llcorner currentpicture);
savepicture:=1;
endchar;
beginchar(fourindic,1636,-1,-1,-1);
%%backgroundimage:images/34.jpg,-756.742,-969.073,1,0,0,1

%%beginpaths

fill
(12,202) .. tension 1 and 3.29726 ..
 {right}(120,349) .. tension 1 and 1 ..
 {down}(128,343) .. tension 1.58017 and 1.57133 ..
(112,298) .. tension 1.70276 and 1.98762 ..
 {down}(64,250) .. tension 1.85734 and 1.15593 ..
 {down}(130,190) .. tension 1 and 5.37804 ..
 {down}(78,82) .. tension 1.60697 and 1 ..
 {right}(111,66) .. tension 0.75 and 2.78999 ..
 {right}(201,90) .. tension 1 and 1 ..
 {down}(210,84) .. tension 2.15303 and 1 ..
 {left}(77,-6) .. tension 1 and 1 ..
 {up}(25.5594,26.3953) .. tension 0.773543 and 3.07729 ..
 {up}(68,144) .. tension 9.08576 and 0.952018 ..
 {up} cycle
;

%%endpaths
%%beginbody


rightbearing := 0;
currentpicture := currentpicture scaled digitscale;
tr_ := tr_ shifted (0,-ypart llcorner currentpicture + 0) ;
savepicture:=1;
endchar;
beginchar(fiveindic,1637,-1,-1,-1);
%%backgroundimage:images/56.jpg,-347,-734,1,0,0,1

%%beginpaths

fill
(31,-110) .. tension 1 and 1.65755 ..
 {right}(134,111) .. tension 1.55619 and 1 ..
 {down}(215,-39) .. tension 1 and 1 ..
 {left}(94,-182) .. tension 1 and 1.30033 ..
 {up} cycle
;
fill
(71,-60) .. tension 1 and 1 ..
 {right}(114,-109) .. tension 0.75 and 2.91894 ..
 {up}(172,-62) .. tension 0.905422 and 3.42169 ..
 {left}(124,26) .. tension 1.64627 and 2.24769 ..
 {down} cycle
;

%%endpaths
%%beginbody

leftbearing := 0;
rightbearing := 0;
currentpicture := currentpicture scaled digitscale;
tr_ := tr_ shifted (0,-ypart llcorner currentpicture + 20) ;
savepicture:=1;
endchar;
beginchar(sixindic,1638,-1,-1,-1);
%%backgroundimage:images/56.jpg,-617,-936,1,0,0,1

%%beginpaths

fill
(-48,313) .. tension 1 and 4.26327 ..
 {right}(-37,341) .. tension 2.02999 and 0.75 ..
 {right}(14,325) .. tension 1 and 1 ..
 {right}(108,332) .. tension 1.58667 and 1 ..
(141,248) .. tension 1 and 2.50743 ..
(172.807,127.596) .. tension 1 and 3.75983 ..
 {down}(207,62) .. tension 1 and 1.0159 ..
 {left}(173,6) .. tension 2.19639 and 1.52788 ..
(115,105) .. tension 1 and 5.93465 ..
(79,256) .. tension 32.6586 and 1 ..
(-20,254) .. tension 1 and 1 ..
 {up} cycle
;

%%endpaths
%%beginbody

leftbearing := 0;
rightbearing := 0;
currentpicture := currentpicture scaled digitscale;
tr_ := tr_ shifted (0,-ypart llcorner currentpicture + 10) ;
savepicture:=1;
endchar;
beginchar(eightindic,1640,-1,-1,-1);
%%backgroundimage:images/89,-388,-972,1,0,0,1

%%beginpaths

fill
(22,1) .. tension 1.64548 and 1 ..
 {up}(-7,70) .. tension 8.11406 and 0.831549 ..
(111,330) .. tension 1 and 1.26138 ..
 {right}(130,362) .. tension 0.902747 and 3.44194 ..
(145,343) .. tension 0.75 and 8.23757 ..
 {down}(254.281,66.9841) .. tension 1 and 1.51709 ..
 {left}(225,2) .. tension 1.88835 and 9.10219 ..
 {left}(124.747,183.295) .. tension 6.33268 and 2.23267 ..
 {left} cycle
;

%%endpaths
%%beginbody


leftbearing := 0;
rightbearing := 0;
currentpicture := currentpicture scaled digitscale;
tr_ := tr_ shifted (0,-ypart llcorner currentpicture + 0) ;
savepicture:=1;
endchar;
beginchar(sevenindic,1639,-1,-1,-1);
%%backgroundimage:images/174.jpg,-1870.05,-1001.22,1,0,0,1

%%beginpaths

fill
(-8,266) .. tension 1 and 1.4916 ..
 {right}(22,340) .. tension 5.01019 and 1.44149 ..
(113.329,208.574) .. tension 1 and 7.40182 ..
 {right}(134,173) .. tension 8.78231 and 4.29673 ..
 {right}(212,363) .. tension 2.11447 and 0.997834 ..
 {down}(244,289) .. tension 8.0593 and 0.75 ..
(189,146) .. tension 1 and 5.79962 ..
 {left}(147,-5) .. tension 2.79745 and 1 ..
(80,136) .. tension 1 and 3.85191 ..
 {up} cycle
;

%%endpaths
%%beginbody

leftbearing := 0;
rightbearing := 0;
currentpicture := currentpicture scaled digitscale;
tr_ := tr_ shifted (0,-ypart llcorner currentpicture + 0) ;
savepicture:=1;
endchar;
beginchar(nineindic,1641,-1,-1,-1);
%%backgroundimage:images/89.jpg,-681,-971.037,1,0,0,1

%%beginpaths

fill
(-14,227) .. tension 1 and 1.39223 ..
 {right}(71,383) .. tension 1.46391 and 1.13319 ..
(164,147) .. tension 0.762016 and 4.92235 ..
 {down}(196,47) .. tension 1.38635 and 1.22263 ..
 {left}(168.981,0) .. tension 1.48355 and 2.52864 ..
 {dir 102.333}(100,182) {dir -174.638} .. tension 1.4844 and 1.07986 ..
(10,193) .. tension 1 and 2.41462 ..
 {up} cycle
;
fill
(36,278) .. tension 1.85915 and 0.75 ..
 {right}(63,255) .. tension 0.75 and 1.52871 ..
 {up}(81,278) .. tension 0.956518 and 1.1647 ..
 {left}(59,302) .. tension 0.75 and 2.62157 ..
 {down} cycle
;

%%endpaths
%%beginbody

leftbearing := 0;
rightbearing := 0;
currentpicture := currentpicture scaled digitscale;
tr_ := tr_ shifted (0,-ypart llcorner currentpicture + 0) ;
savepicture:=1;
endchar;
beginchar(tatweel,1600,250,104,0);
%%beginbody
% glyphname:tatweel
%%begincomponents
%%endcomponents
fill (0.0,0.0)
 .. controls (-20.0,0.0) and (-20.0,0.0) .. (-20.0,52.0)
 .. controls (-20.0,lineheight) and (-20.0,lineheight) .. (0.0,lineheight)
 .. controls (78.0,lineheight) and (172.0,lineheight) .. (250.0,lineheight)
 .. controls (270.0,lineheight) and (270.0,lineheight) .. (270.0,52.0)
 .. controls (270.0,0.0) and (270.0,0.0) .. (250.0,0.0)
 .. controls (172.0,0.0) and (78.0,0.0) .. cycle;
endchar;
beginchar(tatweel.fina,-1,-1,-1,-1);
%%beginbody
% glyphname:tatweel
%%begincomponents
%%endcomponents
fill (0.0,0.0)
 .. controls (-20.0,0.0) and (-20.0,0.0) .. (-20.0,52.0)
 .. controls (-20.0,lineheight) and (-20.0,lineheight) .. (0.0,lineheight)
 .. controls (78.0,lineheight) and (172.0,lineheight) .. (250.0,lineheight)
 .. controls (270.0,lineheight) and (270.0,lineheight) .. (270.0,52.0)
 .. controls (270.0,0.0) and (270.0,0.0) .. (250.0,0.0)
 .. controls (172.0,0.0) and (78.0,0.0) .. cycle;
endchar;
defchar(behshape.isol.expa,-1,-1,-1,-1);
%%backgroundimage:images/beh.isol.expa.jpg,-192,-908,1,0,0,1
%%beginparams
z1 = (413,-12);

%%beginverbatim
z2 = z1  + joinvector;

x.tat := -20* nuqta;
x.tat.min := nuqta;

lefttatweel := lefttatweel + 1.5;
%%endverbatim

%%beginpaths

fill
bldmv ( (36,148), (x.tat,0), (x.tat.min,0) ) .. tension 1.27714 and 0.75 ..
 {right}bldmv ( (44,156), (x.tat,0), (x.tat.min,0) ) .. tension 1.60971 and 1.1457 ..
bldmv ( (80,145), (x.tat,5), (x.tat.min,0) ) .. tension 1.31378 and 0.75 ..
bldmv ( (138,121), (x.tat,13), (x.tat.min,0) ) .. tension bldmvi ( 1.83538, 0.05 ) and 0.75 ..
 {right}bldmvi ( z2, (-489,-26) ) .. tension 0.75 and bldmvi ( 4.17939, 1.3 ) ..
 {up}(673,141) .. tension 1.46476 and 3.02424 ..
 {up}(619,221) .. tension 0.75 and 5.44882 ..
 {right}(654,298) .. tension 2.5475 and 0.857184 ..
 {down}(730,148) .. tension bldmvi ( 1.56259, 0.7 ) and 0.75 ..
 {left}bldmvi ( z1, (-489,-26) ) .. tension bldmvi ( 0.75, 0.05 ) and bldmvi ( 3.69777, 0.5 ) ..
 {up} cycle
;

%%endpaths
enddefchar;
defchar(behshape.fina.expa,-1,-1,-1,-1);
%%backgroundimage:images/beh.fina.expa.jpg,-282.819,-1205.92,1,0,0,1
%%beginparams
z1 = (413,-12);

%%beginverbatim
z2 = z1  + joinvector;

x.tat := -20* nuqta;
x.tat.min := nuqta;

lefttatweel := lefttatweel + 1.5;
%%endverbatim

%%beginpaths

fill
bldmv ( (51,161), (x.tat,0), (x.tat.min,0) ) .. tension 1.27714 and 0.75 ..
 {right}bldmv ( (57,170), (x.tat,0), (x.tat.min,0) ) .. tension 0.75 and 1.1457 ..
bldmv ( (80,160), (x.tat,5), (x.tat.min,0) ) .. tension 1.31378 and 0.75 ..
bldmv ( (138,121), (x.tat,13), (x.tat.min,0) ) .. tension bldmvi ( 1.83538, 0.05 ) and 0.75 ..
 {right}bldmvi ( z2, (-489,-26) ) .. tension 1.90236 and bldmvi ( 1.48916, 0.4 ) ..
bldmv ( (676,152), (20,29), (0,0) ) .. tension 1.46476 and 1.38548 ..
 {right}(722,203) .. tension 0.75 and 1.43805 ..
 {down}(733,190) .. tension bldmvi ( 0.975816, 0.85 ) and 0.75 ..
 {left}bldmvi ( z1, (-489,-26) ) .. tension 0.75 and bldmvi ( 2.37689, 0.5 ) ..
 {up} cycle
;
fill
(679,136) --
(719,171) setranchor
brdmv ( (787,0), (-17.3031,6.1398), (-11.4423,-10.326) ) rightjoinii
brdmv ( (712,51), (-17.3031,8.37245), (-20,-30) ) .. tension 0.75 and 2.13785 ..
 cycle
;

%%endpaths
enddefchar;
defchar(shape.expa.i,-1,-1,-1,-1);
%%backgroundimage:images/noon.expa.jpg,-2881.2,-760.88,1,0,0,1
%%beginparams
z1 = (608,43);

%%beginverbatim


minLeft := 0;
maxLeft := 4.7;

%%endverbatim

%%beginpaths

fill
bldmvi ( (-219,36), (-maxLeft * nuqta,-1) ) .. tension 1.23926 and 0.75 ..
 {right}bldmvi ( (-209,52), (-558,0) ) .. tension 10000 and 1 ..
bldmvi ( (-170,19), (-550,-8) ) .. tension 1 and bldmvi ( 1, 0.1 ) ..
 {right}bldmvi ( (201,-138), (-255,-71) ) .. tension 1 and bldmvi ( 3.67654, -0.1 ) ..
 {up}(551,-18) .. tension 0.86298 and 4.47302 ..
 {up}(489,80) .. tension 0.890434 and 1.4933 ..
 {right}(527,168) .. tension 3.46951 and 1.61702 ..
 {down}z1 .. tension 0.75 and 1.281 ..
bldmvi ( (561,-93), (-25,-32) ) .. tension 1.6893 and 0.75 ..
 {left}bldmvi ( (191,-216), (-258,-74) ) .. tension bldmvi ( 1.07207, 0.1 ) and 0.873173 ..
bldmvi ( (-130,-101), (-545,-12) ) .. tension 0.873173 and 0.873173 ..
bldmvi ( (-200,-13), (-560,2) ) .. tension 4.05368 and 2.19145 ..
 {up} cycle
;

%%endpaths
%%beginbody



enddefchar;
defchar(shape.fina.expa.i,-1,-1,-1,-1);
%%beginparams
z2b = (598.433,28.4592);
z4 = (645,42);

%%beginverbatim

z1b = z2b rotatepen 95;


%%endverbatim

%%beginpaths

fill
brdmvi ( z1b, (0,0) ) setranchor
(708,0) rightjoinii
brdmvi ( z2b, (0,0) ) --
 cycle
;

%%endpaths
%%beginbody

picture pic_; pic_ := image(shape.expa.i_(lefttatweel,0));

draw pic_ shifted (z4 - z1);



enddefchar;
defchar(noonshape.expa,-1,-1,-1,-1);
%%beginparams
z1 = (1093,169);

%%beginverbatim

minLeft := 0;
maxLeft := 20;
tatweel_ := -maxLeft * nuqta;

%%backgroundimage:images/noon.expa.jpg,-2383.2,-902.88,1,0,0,1
%%backgroundimage:images/noon.fina.expa.min.jpg,199,-784,1,0,0,1
%%endverbatim

%%beginpaths

fill
bldmvi ( (261,149), (tatweel_,-212.91) ) .. tension 1 and 1 ..
 {right}bldmvi ( (271,164), (-2380.4,-216.587) ) .. tension 1.39521 and 1 ..
bldmvi ( (317,129), (-2274.89,-213.818) ) .. tension 1 and 1 ..
bldmvi ( (473,26), (-2014.62,-185.431) ) .. tension 1 and 1 ..
 {right}bldmvi ( (695,-8), (-1311.38,-256.95) ) .. tension 1 and 1 ..
(946,48) .. tension 3.35294 and 1.88028 ..
 {up}(1037,120) .. tension 0.75 and 2.16809 ..
 {up}(988,223) .. tension 1 and 1.93214 ..
 {right}(1020,303) .. tension 2.73895 and 1 ..
 {down}z1 .. tension 1 and 1 ..
bldmvi ( (990,-20), (-139.096,-56.3702) ) .. tension 1 and 1 ..
 {left}bldmvi ( (688,-103), (-1382.02,-241.193) ) .. tension 1 and 1 ..
bldmvi ( (393,-19), (-2036.25,-214.936) ) .. tension 1 and 1 ..
bldmvi ( (274,119), (-2339.71,-220.892) ) .. tension 3.50509 and 2.41175 ..
 {up} cycle
;

%%endpaths
%%beginbody

setCursiveAnchor(rtlcursive,(15,26.0528)+ z1, EntryAnchorRTL);


show tatweel_;


enddefchar;
defchar(noonshape.fina.expa,-1,-1,-1,-1);
%%beginparams
z2b = (598.433,28.4592);
z4 = (645,42);

%%beginverbatim

z1b = z2b rotatepen 95;


%%endverbatim

%%beginpaths

fill
brdmvi ( z1b, (0,0) ) setranchor
(708,0) rightjoinii
brdmvi ( z2b, (0,0) ) --
 cycle
;

%%endpaths
%%beginbody

picture pic_; pic_ := image(noonshape.expa_(lefttatweel,0));

draw pic_ shifted (z4 - z1);


enddefchar;
defchar(feh.isol.expa,-1,-1,-1,-1);
%%backgroundimage:images/feh.isol.jpg,-110,-1113.27,1,0,0,1
%%beginparams
z1 = (413,-12);
z11 = (457,523);

%%beginverbatim
z2 = z1  + joinvector;

x.tat := -20* nuqta;
x.tat.min := nuqta;

lefttatweel := lefttatweel + 1.5;
%%endverbatim

%%beginpaths

fill
bldmv ( (36,148), (x.tat,0), (x.tat.min,0) ) .. tension 1.27714 and 0.75 ..
 {right}bldmv ( (44,156), (x.tat,0), (x.tat.min,0) ) .. tension 1.60971 and 1.1457 ..
bldmv ( (80,145), (x.tat,5), (x.tat.min,0) ) .. tension 1.31378 and 0.75 ..
bldmv ( (138,121), (x.tat,13), (x.tat.min,0) ) .. tension bldmvi ( 1.83538, 0.05 ) and 0.75 ..
 {right}bldmvi ( z2, (-489,-26) ) .. tension 0.75 and bldmvi ( 4.17939, 1.3 ) ..
 {up}(684,156) .. tension 1.46476 and 1.5825 ..
 {left}(668,204) .. tension 2.45775 and 0.75 ..
 {left}(589,157) .. tension 1.51896 and 1.05766 ..
 {up}(505,239) .. tension 0.75 and 3.67346 ..
 {right}(599,425) .. tension 2.02057 and 0.75 ..
 {down}(734,167) .. tension bldmvi ( 1.31629, 0.7 ) and 0.75 ..
 {left}bldmvi ( z1, (-489,-26) ) .. tension bldmvi ( 0.75, 0.05 ) and bldmvi ( 3.69777, 0.5 ) ..
 {up} cycle
;
fill
(642,288) .. tension 1.95936 and 1 ..
 {left}(597,329) .. tension 2.13457 and 1 ..
 {down}(561,292) .. tension 1 and 1 ..
 {right}(612,256) .. tension 1 and 1 ..
 cycle
;

%%endpaths
%%beginbody

draw one_dot.pic  shifted z11;


enddefchar;
defchar(feh.fina.expa,-1,-1,-1,-1);
%%backgroundimage:images/feh.fina.jpg,-94.0184,-945.263,1,0,0,1
%%beginparams
z1 = (731,363);
z10 = (413,-12);
z11 = (541,438);
z2 = (710,270);

%%beginverbatim
z20 = z10  + joinvector;

x.tat := -20* nuqta;
x.tat.min := nuqta;

lefttatweel := lefttatweel + 1.5;
%%endverbatim

%%beginpaths

fill
bldmv ( (51,161), (x.tat,0), (x.tat.min,0) ) .. tension 1.27714 and 0.75 ..
 {right}bldmv ( (57,170), (x.tat,0), (x.tat.min,0) ) .. tension 0.75 and 1.1457 ..
bldmv ( (80,160), (x.tat,5), (x.tat.min,0) ) .. tension 1.31378 and 0.75 ..
bldmv ( (138,121), (x.tat,13), (x.tat.min,0) ) .. tension bldmvi ( 1.83538, 0.05 ) and 0.75 ..
 {right}bldmvi ( z20, (-489,-26) ) .. tension bldmvi ( 1.90236, -0.3 ) and bldmvi ( 2.93979, 1 ) ..
 {up}(750,195) .. tension 1.46476 and 1.70493 ..
 {left}z2 .. tension 5.45068 and 4.46006 ..
 {right}z1 .. tension 1.90983 and 1 ..
 {down}(808,200) .. tension bldmvi ( 2.06269, 0.5 ) and 0.75 ..
 {left}bldmvi ( z10, (-489,-26) ) .. tension 0.75 and bldmvi ( 2.37689, 0.5 ) ..
 {up} cycle
;
fill
(596,177) .. tension 1 and 2.1057 ..
 {right}z1 .. tension 3.20057 and 6.45091 ..
 {left}z2 .. tension 1.2979 and 1.76858 ..
 {down}(646,204) .. tension 1.06071 and 1 ..
brdmv ( (738,115), (4,7), (-1,-23) ) setranchor
(851,0) rightjoinii
brdmv ( (734,20), (0,0), (-6,-35) ) ..
brdmv ( (637,73), (0,0), (0,-37) ) .. tension 1 and 1 ..
 {up} cycle
;

%%endpaths
%%beginbody

draw one_dot.pic  shifted z11;
enddefchar;
defchar(kaf.fina.expa,-1,-1,-1,-1);
%%backgroundimage:images/kaf.fina.expa.jpg,-772.086,-839.579,1,0,0,1
%%beginparams
rightVerticalRatio := 5;
z1 = (-265,0);
z1.delta = (-1589,-99);
z11 = bldmvi ( (-257,169), (-420,21) );

%%beginverbatim

minLeft := 0;
maxLeft := 20;

numeric _tatweel;
_tatweel := maxLeft * nuqta;


z2 = z1  + joinvector;

x.tat := -20* nuqta;
x.tat.min := nuqta;

lefttatweel := lefttatweel + 1.5;
%%endverbatim

%%beginpaths

fill
(83,507) .. tension 1.29322 and 2.09511 ..
 {right}(111,576) .. tension 1.60462 and 1.61658 ..
(133,553) .. tension 11.4991 and 2.76737 ..
(162,398) .. tension 1.51205 and 2.71461 ..
brdmv ( (196,176), (21,-56), (0,0) ) .. tension brdmvi ( 1, 0.05 ) and 1 ..
brdmv ( (246,92), (397,-338), (-77,-1) ) setranchor
(255,-1) rightjoinii
brdmv ( (189,19), (490,-386), (-20,-25) ) .. tension atleast 1 ..
(138,108) .. tension 2.00581 and 1 ..
(106,390) .. tension 1 and 5.69625 ..
 {up} cycle
;
fill
bldmv ( (-517,152), (x.tat,0), (x.tat.min,0) ) .. tension 1.27714 and 0.75 ..
 {right}bldmv ( (-509,163), (x.tat,0), (x.tat.min,0) ) .. tension 1.45412 and 1.1457 ..
bldmv ( (-489,153), (x.tat,5), (x.tat.min,0) ) .. tension 1.31378 and 0.75 ..
bldmv ( (-447,129), (x.tat,13), (x.tat.min,0) ) .. tension bldmvi ( 1.83538, 0.05 ) and 0.75 ..
 {right}bldmvi ( z2, z1.delta ) .. tension 1.60953 and 1.37771 ..
bldmvi ( (144,217), (-13,29) ) .. tension bldmvi ( 0.96689, 0.4 ) and bldmvi ( 2.09318, 0.4 ) ..
bldmvi ( (157,256), (0,0) ) --
bldmvi ( (172,171), (0,0) ) .. tension 2.166 and 1.054 ..
bldmvi ( (153,143), (-7,19) ) .. tension 1.1819 and 1.1819 ..
 {left}bldmvi ( z1, z1.delta ) .. tension 1.11805 and bldmvi ( 2.03734, 1.9 ) ..
 {up} cycle
;

%%endpaths
%%beginbody

draw minikaf.pic  shifted z11;
enddefchar;
defchar(kaf.fina.afterlam.expa,-1,-1,-1,-1);
%%backgroundimage:images/kaf.fina.expa.jpg,-772.086,-839.579,1,0,0,1
%%beginparams
rightVerticalRatio := 5;
z1 = (-265,0);
z1.delta = (-1589,-99);
z11 = bldmvi ( (-257,169), (-420,21) );

%%beginverbatim

minLeft := 0;
maxLeft := 20;

numeric _tatweel;
_tatweel := maxLeft * nuqta;


z2 = z1  + joinvector;

x.tat := -20* nuqta;
x.tat.min := nuqta;

lefttatweel := lefttatweel + 1.5;
%%endverbatim

%%beginpaths

fill
(83,507) .. tension 1.29322 and 2.09511 ..
 {right}(111,576) .. tension 1.60462 and 1.61658 ..
(133,553) .. tension 11.4991 and 2.76737 ..
(162,398) .. tension 1.51205 and 2.71461 ..
brdmv ( (196,176), (21,-56), (0,0) ) .. tension brdmvi ( 1, 0.05 ) and 1 ..
brdmv ( (264,41), (397,-338), (-72,17) ) setranchor
(289,-59) rightjoinii
brdmv ( (225,-42), (490,-386), (-70,32) ) .. tension atleast 1 ..
(146,106) .. tension 2.00581 and 1 ..
(106,390) .. tension 1 and 5.69625 ..
 {up} cycle
;
fill
bldmv ( (-517,152), (x.tat,0), (x.tat.min,0) ) .. tension 1.27714 and 0.75 ..
 {right}bldmv ( (-509,163), (x.tat,0), (x.tat.min,0) ) .. tension 1.45412 and 1.1457 ..
bldmv ( (-489,153), (x.tat,5), (x.tat.min,0) ) .. tension 1.31378 and 0.75 ..
bldmv ( (-447,129), (x.tat,13), (x.tat.min,0) ) .. tension bldmvi ( 1.83538, 0.05 ) and 0.75 ..
 {right}bldmvi ( z2, z1.delta ) .. tension 1.60953 and 1.37771 ..
bldmvi ( (144,217), (-13,29) ) .. tension bldmvi ( 0.96689, 0.4 ) and bldmvi ( 2.09318, 0.4 ) ..
bldmvi ( (157,256), (0,0) ) --
bldmvi ( (172,171), (0,0) ) .. tension 2.166 and 1.054 ..
bldmvi ( (153,143), (-7,19) ) .. tension 1.1819 and 1.1819 ..
 {left}bldmvi ( z1, z1.delta ) .. tension 1.11805 and bldmvi ( 2.03734, 1.9 ) ..
 {up} cycle
;

%%endpaths
%%beginbody

draw minikaf.pic  shifted z11;

enddefchar;
defchar(noon.isol.expa,-1,-1,-1,-1);
%%backgroundimage:images/noon.expa.jpg,-2383.2,-902.88,1,0,0,1
%%beginparams
z1 = (1102.11,172.153);
z11 = (613.443,186.105);

%%beginverbatim

minLeft := 0;
maxLeft := 20;
tatweel_ := -maxLeft * nuqta;

%%backgroundimage:images/noon.expa.jpg,-2383.2,-902.88,1,0,0,1
%%backgroundimage:images/noon.fina.expa.min.jpg,199,-784,1,0,0,1
%%endverbatim

%%beginpaths

fill
bldmvi ( (270.217,151.563), (tatweel_,-212.91) ) .. tension 1 and 1 ..
 {right}bldmvi ( (280.151,167.349), (-2380.4,-216.587) ) .. tension 1.39521 and 1 ..
bldmvi ( (326.099,132.233), (-2274.89,-213.818) ) .. tension 1 and 1 ..
bldmvi ( (482.095,28.803), (-2014.62,-185.431) ) .. tension 1 and 1 ..
 {right}bldmvi ( (704.175,-5.07222), (-1311.38,-256.95) ) .. tension 1 and 1 ..
(955.153,50.6131) .. tension 3.35294 and 1.88028 ..
 {up}(1046.4,122.638) .. tension 0.75 and 2.16809 ..
 {up}(996.556,225.585) .. tension 1 and 1.93214 ..
 {right}(1028.71,306.344) .. tension 2.73895 and 1 ..
 {down}z1 .. tension 1 and 1 ..
bldmvi ( (998.824,-16.8277), (-139.096,-56.3702) ) .. tension 1 and 1 ..
 {left}bldmvi ( (696.919,-99.656), (-1382.02,-241.193) ) .. tension 1 and 1 ..
bldmvi ( (401.652,-16.4812), (-2036.25,-214.936) ) .. tension 1 and 1 ..
bldmvi ( (282.588,122.069), (-2339.71,-220.892) ) .. tension 3.50509 and 2.41175 ..
 {up} cycle
;

%%endpaths
%%beginbody





x11 := x11 - lefttatweel *  nuqta / 2;

draw one_dot.pic  shifted z11;

setCursiveAnchor(rtlcursive,(15,26.0528)+ z1, EntryAnchorRTL);

show tatweel_;

enddefchar;
defchar(noon.fina.expa.afterbeh,-1,-1,-1,-1);
%%beginparams
z1.mark = (1074,152);
%%beginbody


noon.isol.expa_(lefttatweel,0);



setCursiveAnchor(rtlcursive,z1.mark, EntryAnchorRTL);




enddefchar;
defchar(noon.fina.expa,-1,-1,-1,-1);
%%backgroundimage:images/noon.fina.expa.min.jpg,-256.833,-643,1,0,0,1
%%beginparams
rightVerticalRatio := 6;
z2b = (598.433,28.4592);
z4 = (645,8.33337);

%%beginverbatim

z1b = z2b rotatepen 95;

righttatweel := righttatweel  + 0.0;



%%endverbatim

%%beginpaths

fill
brdmvi ( z1b, (0,0) ) setranchor
(708,0) rightjoinii
brdmvi ( z2b, (0,0) ) --
 cycle
;

%%endpaths
%%beginbody

picture pic_; pic_ := image(noon.isol.expa_(lefttatweel,0));

draw pic_ shifted (z4 - z1);



enddefchar;
defchar(noon.fina.basmala,-1,-1,-1,-1);
%%beginparams
z.t.1 = bldmvi ( (255,210), (410,10) );
%%beginbody

noon.fina.expa_(lefttatweel,righttatweel);


picture q;
q := currentpicture;
a := 0;
currentpicture := nullpicture;



pair p_;

for item within q:
  if filled item :
	p := pathpart item;
  if a = 2 : 
    p_ = point 0 of p;
    fill p shifted (z.t.1 ); 
  else :
    if filled item : fill p; fi;    
  fi
  a := a + 1;
    
  fi;
 
endfor


enddefchar;
defchar(sad.isol.expa,-1,-1,-1,-1);
%%beginbody




sad.shape.ii_(0,0);


pair shift_;
picture pic_;

pic_ := image(
pair tt__;
tt__ := z1;
save rightanchor;pair rightanchor;clearxy;
shape.fina.expa.i_(lefttatweel,0.5);
show rightanchor,z1;
shift_ := tt__ - rightanchor;
);

draw pic_ shifted shift_;


pair leftanchor;


enddefchar;
defchar(sad.fina.expa,-1,-1,-1,-1);
%%beginparams
z10 = (584,0);

%%beginpaths

fill
(530,90) setranchor
z10 rightjoinii
(431,9) --
 cycle
;

%%endpaths
%%beginbody

begingroup
pair rightanchor;clearxy;
sad.isol.expa_(lefttatweel,righttatweel);
endgroup;


rightanchor := z10;

enddefchar;
defchar(yehshape.fina.ii.expa,-1,-1,-1,-1);
%%backgroundimage:images/yehexpa.jpg,-1060.5,-900.344,1,0,0,1
%%beginparams
z1 = (381,56);
z2 = (613,64);

%%beginverbatim

minLeft := 0;
maxLeft := 7;
tatweel_ := -maxLeft * nuqta;
z3 = z1 + (76,83);

%%endverbatim

%%beginpaths

fill
bldmvi ( (-218.01,69.2754), (tatweel_,0) ) .. tension 1.15253 and 0.75 ..
 {right}bldmvi ( (-207.36,86.0972), (tatweel_,0) ) .. tension 4.23996 and 0.75 ..
bldmvi ( bldmvi ( (-30.7361,-38.7533), (tatweel_,0) ), (-10.6811,15.9511) ) .. tension 1.50093 and 1 ..
 {right}bldmvi ( (209.646,-106.77), (-362.58,-42.88) ) .. tension 1 and bldmvi ( 8.62678, -0.2 ) ..
 {up}(538.677,17.337) .. tension 4.09775 and 1 ..
(452.094,48.9962) .. tension 0.891928 and 2.18505 ..
 {left}z1 {dir 20} .. tension 5.31977 and 2.9362 ..
 {right}z3 .. tension 0.75 and 1.43919 ..
(574.74,109.66) .. tension 1 and 1 ..
 {down}z2 .. tension bldmvi ( 1.63545, 0.25 ) and 1 ..
 {left}bldmvi ( (206.943,-190.752), (-387.06,-48.64) ) .. tension 1 and 1.23984 ..
bldmvi ( bldmvi ( (-58.3844,-115.002), (tatweel_,0) ), (98.62,-25.2344) ) .. tension 1 and 1.78941 ..
 {up} cycle
;

%%endpaths
%%beginbody
rightbearing := x1 - x2;
setCursiveAnchor(ltrcursive,z1,EntryAnchor);
enddefchar;
defchar(alefmaksura.isol.expa,-1,-1,-1,-1);
%%beginbody

%%beginbody
yehshape.fina.ii.expa_(lefttatweel,0);

pair shift_;
picture pic_;

pic_ := image(
yeh.shape.i_(0,0);
shift_ := z1 - z.yeh.shape.i.1;
);

draw pic_ shifted shift_;
rightbearing := 0;


enddefchar;
defchar(yehshape.isol.expa,-1,-1,-1,-1);
%%beginbody
alefmaksura.isol.expa_(lefttatweel,0);
enddefchar;
defchar(yehshape.fina.expa,-1,-1,-1,-1);
%%beginbody

%%beginbody
yehshape.fina.ii.expa_(lefttatweel,0);

pair shift_;
picture pic_;

pic_ := image(
yeh.shape.ii_(0,righttatweel);
shift_ := z1 - z.yeh.shape.ii.1;
);

draw pic_ shifted shift_;
rightanchor := rightanchor shifted shift_;;
rightbearing := 0;

tr_ := tr_ shifted (0, -ypart rightanchor);



enddefchar;
defchar(seen.isol.expa,-1,-1,-1,-1);
%%backgroundimage:images/seen.isol.expa.jpg,-1283,-937,1,0,0,1
%%beginparams
z.mark1 = bldmvi ( (227,-114), (-55,-83) );
%%beginbody

seen.twosinnas_(-0.5,0);

pair shift_;
picture pic_;

pic_ := image(
save rightanchor;pair rightanchor;clearxy;
shape.fina.expa.i_(lefttatweel,-0.6);
shift_ := leftanchor - rightanchor;
);

draw pic_ shifted shift_;

defAnchor(lowmarks,z.mark1,MarkAnchor);
defAnchor(lowmarkafterwawandreh.lowmarks.l4_kasra   ,z.mark1,MarkAnchor);

pair leftanchor;

enddefchar;
defchar(seen.fina.expa,-1,-1,-1,-1);
%%beginparams
z.mark1 = bldmvi ( (106,344), (-277,6) );
%%beginbody

%%beginbody

seen.twosinnas.medi_(-0.7,righttatweel);

pair shift_;
picture pic_;

pic_ := image(
save rightanchor;pair rightanchor;clearxy;
shape.fina.expa.i_(lefttatweel,-0.4);
shift_ := leftanchor - rightanchor;
);

draw pic_ shifted shift_;

pair leftanchor;



defAnchor(defaultmarkposition_topmarks   ,z.mark1,MarkAnchor);

enddefchar;
defchar(qaf.isol.expa,-1,-1,-1,-1);
%%backgroundimage:images/qaf.fina.expa.jpg,-722.912,-986.8,1,0,0,1
%%beginparams
z.mark1 = bldmvi ( (430,-237), (-55,-83) );
z.two_dots = (275,365);
z1 = (482,256);
z2 = (450,167);

%%beginverbatim


minLeft := 0;
maxLeft := 4.7;

%%endverbatim

%%beginpaths

fill
bldmvi ( (-219,36), (-maxLeft * nuqta,-1) ) .. tension 1.23926 and 0.75 ..
 {right}bldmvi ( (-209,52), (-558,0) ) .. tension 10000 and 1 ..
bldmvi ( (-170,19), (-550,-8) ) .. tension 1 and bldmvi ( 1, 0.1 ) ..
 {right}bldmvi ( (201,-138), (-255,-71) ) .. tension 1 and bldmvi ( 3.67654, -0.1 ) ..
 {up}(551,-18) .. tension 0.86298 and 4.47302 ..
(480,143) .. tension 0.890434 and 1.4933 ..
 {left}z2 .. tension 5.44047 and 3.40173 ..
 {right}z1 .. tension 3.46951 and 1.61702 ..
 {down}(608,43) .. tension 0.75 and 1.281 ..
bldmvi ( (561,-93), (-25,-32) ) .. tension 1.6893 and 0.75 ..
 {left}bldmvi ( (191,-216), (-258,-74) ) .. tension bldmvi ( 1.07207, 0.1 ) and 0.873173 ..
bldmvi ( (-130,-101), (-545,-12) ) .. tension 0.873173 and 0.873173 ..
bldmvi ( (-200,-13), (-560,2) ) .. tension 4.05368 and 2.19145 ..
 {up} cycle
;
fill
(384,49) .. tension 1 and 1 ..
 {up}(377,93) .. tension 1.06192 and 2.73766 ..
z1 {right} .. tension 3.00215 and 4.73364 ..
z2 {left} .. tension 2.21643 and 1.47953 ..
 {down}(425,127) .. tension 1.08819 and 1 ..
(431,106) link
(569,-1) ..
 cycle
;

%%endpaths
%%beginbody
draw two_dots.pic shifted z.two_dots;

tr_ := tr_ shifted (0,100);

defAnchor(lowmarks,z.mark1,MarkAnchor);
defAnchor(lowmarkafterwawandreh.lowmarks.l4_kasra   ,z.mark1,MarkAnchor);

enddefchar;
defchar(behshape.init.bseen.basmala,-1,-1,-1,-1);
%%backgroundimage:images/bism.jpg,-9840.37,-1037.96,1,0,0,1
%%beginparams
z.mark1 = (124,112);
z1 = (205,92);

%%beginverbatim

lefttatweel := lefttatweel +0;






%%endverbatim

%%beginpaths

fillc
(92,41) {dir -206.913} .. tension 3.35106 and 1 ..
 {dir 45}z.mark1 {dir -22.584} .. tension 0.852509 and 1.2775 ..
 {right}z1 .. tension 1.18171 and 2.24363 ..
 {up}(251,102) .. tension 1.58647 and 1 ..
(230,179) .. tension 0.762144 and 3.08027 ..
 {dir 133.393}(186,270) {dir -145.534} .. tension 0.75 and 1.43213 ..
 {left}(161,260) .. tension 1.61649 and 0.75 ..
 {up}(137,314) .. tension 1.07543 and 1.91018 ..
 {right}(172,404) .. tension 2.04054 and 1 ..
(261,270) .. tension 1.12129 and 0.88406 ..
 {down}(294,119) .. tension 8.94193 and 0.75 ..
 {left}(235,6) .. tension atleast 0.828418 ..
 cycle
;

%%endpaths
%%beginbody

setCursiveAnchor(rtlcursive,z.mark1 ,ExitAnchorRTL);



enddefchar;
defchar(seen.medi.basmala,-1,-1,-1,-1);
%%backgroundimage:images/bism.jpg,-9327.25,-1050.5,1,0,0,1
%%beginparams
leftVerticalRatio := 10;
z.mark1 = (643,142);

%%beginverbatim






%%endverbatim

%%beginpaths

fill
(321,135) .. tension 1 and 1.11556 ..
 {right}(340,145) .. tension 1.0342 and 0.957132 ..
 {down}(351,128) .. tension 1 and 3.68169 ..
 {down}(330,87) .. tension 1.58977 and 1 ..
 {right}(388,66) .. tension 1 and 1.0044 ..
(483,99) .. tension 1 and 1.19775 ..
 {right}(543,150) .. tension 1.31024 and 1 ..
 {down}(555,138) .. tension 3.05237 and 2.90237 ..
 {down}(546,99) .. tension 2.23839 and 1.70605 ..
 {right}(567,88) .. tension 1 and 1.01107 ..
 {right}(660,169) .. tension 2.50477 and 1 ..
 {down}(671,161) .. tension 1.56 and 2.28455 ..
 {left}(552,3) .. tension 0.75 and 10.3975 ..
 {left}(489,22) .. tension 14.3471 and 0.75 ..
 {left}(387,-10) .. tension 0.75 and 2.94203 ..
 {left}(290,47) .. tension 1.26465 and 1.31377 ..
(282,44) .. tension 1.1434 and 1.1434 ..
bldmv ( (226,18), (0,0), (0,0) ) leftjoin
bldmv ( (261,97), (-37.7765,-9.64506), (17.6826,15.6732) ) .. tension 0.919648 and 1.14905 ..
 cycle
;

%%endpaths
%%beginbody

setCursiveAnchor(rtlcursive,z.mark1 ,EntryAnchorRTL);


enddefchar;
defchar(meem.fina.basmala,-1,-1,-1,-1);
%%backgroundimage:images/bism.jpg,-7304,-1050.5,1,0,0,1
%%beginparams
rightVerticalRatio := 10;
z.mark1 = (295,-194);

%%beginverbatim

righttatweel := righttatweel - 0.0;



%%endverbatim

%%beginpaths

fill
(184,-3) .. tension 0.75 and 1 ..
 {up}(169,61) .. tension 1.73037 and 1.61706 ..
 {right}(276,153) .. tension 1.33966 and 1 ..
(341,107) .. tension 1 and 1 ..
brdmv ( (453,57), (89,-25), (-10,-27) ) setranchor
(498,-36) rightjoinii
brdmv ( (383,-6), (0,0), (-1,-25) ) {curl1} .. tension 1.3164 and 2.03251 ..
 {left}(351,-58) .. tension 1.46691 and 6.1513 ..
 {left}(218,-32) .. tension 5.41352 and 5.43489 ..
(200,-50) .. tension 0.989106 and 18.3373 ..
 {left}(-81,-145) .. tension 1 and 1 ..
 {up}(-92,-131) .. tension 2.77906 and 1 ..
(8,-89) .. tension 1.73988 and 6.20895 ..
 {up} cycle
;
fill
(258,96) .. tension 1.23804 and 1.74187 ..
 {down}(232,72) .. tension 6.28125 and 2.6024 ..
 {up}(303,45) .. tension 1.82811 and 3.01664 ..
 {left} cycle
;

%%endpaths
%%beginbody
%%beginbody
leftbearing :=- 50;

setMarkAnchor(buttonmark,z.mark1);

enddefchar;
defchar(behshape.medi.basmala,-1,-1,-1,-1);
%%backgroundimage:images/basmala.4.jpg,-2859.82,-940.951,1,0,0,1
%%beginparams
leftVerticalRatio := 6;
z.mark1 = (256.909,80.176);
z1 = (172,131);

%%beginverbatim

%%endverbatim

%%beginpaths

fill
(195.742,156.111) .. tension 1.74567 and 1 ..
(147.893,69.9612) .. tension 1 and 1 ..
bldm ( (103.204,34.9645), (-48.8057,-29.6825) ) ..
bldm ( (60.5803,13.8041), (-805.69,-278.19) ) ..
bldm ( (-12.9554,-4.75253), (-1782.72,-393.12) ) ..
bldm ( (-33.7049,-6.08523), nuqta * (-21,-21 / leftVerticalRatio) ) link
bldm ( (3.31284,83.6499), (-1848.96,-396) ) ..
bldm ( (78.9243,106.392), (-856.691,-285.338) ) ..
bldm ( (126.541,129.963), (-284.709,-137.548) ) .. tension 1 and 1 ..
(161.692,152.362) .. tension 1 and 2.6577 ..
 {right}(187.455,168.197) .. tension 1 and 1 ..
 {down} cycle
;

%%endpaths
%%beginbody
setCursiveAnchor(rtlcursive,z1,EntryAnchorRTL);
setMarkAnchor(twodotsdown,z.mark1);

enddefchar;
defchar(hah.init.basmala,-1,-1,-1,-1);
%%backgroundimage:images/basmala.4.jpg,-3049.4,-958.334,1,0,0,1
%%beginparams
z1 = (-20.0402,147.686);

%%beginverbatim


%%endverbatim

%%beginpaths

fill
(-37.0604,100.575) {dir -252.1} .. tension 1.74486 and 1.85096 ..
 {dir 45}z1 {dir -45} .. tension 5.68827 and 0.75 ..
 {right}(67.7083,114.005) .. tension 1 and 36.9116 ..
 {dir 25.8348}(382.46,201.475) {dir -242.953} .. tension 12.5779 and 1.65326 ..
 {left}(180.454,255.94) .. tension 0.75 and 1.21121 ..
(77.9196,229.406) .. tension 1 and 6.40635 ..
 {left}(45.583,208.46) .. tension 1 and 1 ..
 {up}(38.3177,218.749) .. tension 4.72612 and 0.750683 ..
 {right}(182.379,354.361) .. tension 1.0997 and 1 ..
(336.186,297.964) .. tension 1 and 1.73076 ..
 {right}(632.687,243.357) .. tension 1 and 5.56899 ..
 {down}(702.364,241.338) .. tension 3.90761 and 17.8421 ..
 {left}(658.858,162.778) .. tension 3.18506 and 0.75 ..
 {left}(581.221,173.437) .. tension 2.41416 and 0.75 ..
(513.068,169.494) .. tension 1.05124 and 3.64317 ..
 {left}(109.532,33.0764) .. tension 1.33992 and 5.87146 ..
 {up} cycle
;

%%endpaths
%%beginbody

setCursiveAnchor(rtlcursive,z1,ExitAnchorRTL);
enddefchar;
