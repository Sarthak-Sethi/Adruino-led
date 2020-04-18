const int lm35_pin = A1;  /* LM35 O/P pin */
const int lm35_pin2 = A2;
int out = 9;
  int bri=0;
   
  int temp_adc_val;
  int temp_adc_val2;
  int temp_vala;
  int temp_vala2;
  float temp_val;
  float temp_val2;
  float temp;
  int maxi=84;
void setup() {
  Serial.begin(9600);
  pinMode(out,OUTPUT);
  
}

void loop() {

  temp_adc_val = analogRead(lm35_pin);  /* Read Temperature */
  temp_adc_val2 = analogRead(lm35_pin2);  /* Read Temperature */
  temp_val = (temp_adc_val * 4.88); /* Convert adc value to equivalent voltage */
  temp_val2 = (temp_adc_val2 * 4.88); /* Convert adc value to equivalent voltage */
  temp_val = (temp_val/10); /* LM35 gives output of 10mv/°C */
  temp_val2 = (temp_val2/10); /* LM35 gives output of 10mv/°C */
  Serial.print("Temperature1 = ");
  Serial.print(temp_val);
  Serial.print(" Degree Celsius");
  Serial.print("  Temperature2 = ");
  Serial.print(temp_val2);
  Serial.print(" Degree Celsius\n");
  //delay(1000);
  
   temp= (temp_val+temp_val2)/2;
    Serial.println(temp);
   if(temp<maxi)
   {
     if(bri<200)
     bri=bri+1;
    }
    if ( temp>maxi  ){
  
 bri= bri-20;
 delay(5000);
 
 }
 
 analogWrite(out, bri);
 Serial.println(bri);
}
