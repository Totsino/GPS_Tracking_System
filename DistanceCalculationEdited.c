// DISTANCE CALCULATION BETWEEN TWO COORDINATES
//  lat_init, lon_init,  lat_final,  lon_final will be recieved from GPS_UART Module

//  HAVERSINE FORMULA

double calc_Distance(double lat_init, double lon_init, double lat_final, double lon_final) {

double difference_Lon;
double difference_Lat ;
double a ;
double c ;
double distance; 
			
    double pi = 3.141592653589793;
    int Earth_Radius = 6371; //Radius of the Earth
    lat_init = (pi/180)*(lat_init);
    lon_final = (pi/180)*(lon_final);
    difference_Lon = (pi/180)*(lon_final- lon_init);
    difference_Lat = (pi/180)*(lat_final - lat_init);
    a = sin(difference_Lat/2) * sin(difference_Lat/2) + 
    cos(lat_init) * cos(lon_final) * 
    sin(difference_Lon/2) * sin(difference_Lon/2);
    c = 2 * atan2(sqrt(a), sqrt(1-a));
    distance = (Earth_Radius * c);
    return distance*1000;
}