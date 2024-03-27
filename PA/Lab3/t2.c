char ** s ;
char eroare [] = " Segmentation Fault " ;
* s = eroare ;
printf ( " s : % s \ n " ,s );
s [0] = eroare ;
printf ( " s [0]: % s \ n " ,s );

