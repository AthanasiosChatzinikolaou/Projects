translate([14,0,-11])
{
    difference()
    {
        cube([4,4,2], center = true);
        translate([0,0,0.21])
        cube([3.8,3.8,2], center = true);
    }
    }

translate([19,-7,-7])
cube([1,14,14]);

    difference()
    {
translate([19,0,-7])
    rotate([0,90,0])
cylinder(1,7,7,$fn=4);
translate([18.9,-2.5,-17])
cube([5,5,5]); 
    }
// door of furnace

rotate([0,90,0])
{    
translate([-2,0,10])
cylinder(r=0.5,h=9,$fa=0.2, $fs=0.2);
}
// hanger of aluminium

rotate([0,90,0])
{    
translate([11,0,16])
cylinder(r=0.5,h=3,$fa=0.2, $fs=0.2);
}


rotate([0,90,0])
{    
translate([4,5.5,0])
cube([0.5,0.5,19]);
translate([3.5,5.5,0])
cube([0.5,0.5,0.5]);
translate([4,-6,0])
cube([0.5,0.5,19]); 
translate([3.5,-6,0])
cube([0.5,0.5,0.5]);
}
// door rails


translate([0,0,0])
{
difference()
{
rotate([0,0,45])
{
translate([0,0,-10])
cylinder(5,3,7,$fn=4);
}
rotate([0,0,45])
{
translate([0,0,-11])
cylinder(8,0.5,8.5,$fn=4);
}
}
}
// piramid



#difference()
{ 
    translate([-6,0,0])
    cube([22,14,14], center=true);
    translate([-16,-6.5,-6.5])
    cube([22,13,13]);
    rotate([0,0,45])
{
translate([0,0,-9.99])
cylinder(5,3,7,$fn=4);
}
rotate([90,0,0])
cylinder(r=0.8,h=20,$fa=0.2, $fs=0.2);
}
difference()
{
rotate([90,0,0])
translate([0,0,5])
    cylinder(r=0.8,h=5,$fa=0.2, $fs=0.2);
    rotate([90,0,0])
translate([0,0,4.99])
    cylinder(r=0.7,h=5.1,$fa=0.2, $fs=0.2);
}
difference()
{
rotate([0,00,90])
translate([-11,0,1])
    cylinder(r=0.8,h=8,$fa=0.2, $fs=0.2);
    rotate([0,0,90])
translate([-11,0,1])
    cylinder(r=0.7,h=8.1,$fa=0.2, $fs=0.2);
}
difference()
{
translate([0,-11,0])
cube([2,2,2], center=true);
  translate([0,-11,0])
 cube([1.8,1.8,1.8], center=true); 
      rotate([0,0,90])
translate([-11,0,1])
    cylinder(r=0.7,h=8.1,$fa=0.2, $fs=0.2);
       rotate([90,0,0])
translate([0,0,4.99])
    cylinder(r=0.7,h=5.1,$fa=0.2, $fs=0.2); 
}
//external frame

difference()
{ 
    cube([10,10,10], center=true);
    rotate([90,0,0])
    cylinder(r=0.8,h=20,$fa=0.2, $fs=0.2);
    translate([-4,-4.5,-5.01])
    cube([10,9,9.5]);
}
//internal frame