class RippleGenerator
{
  int net_w = 3200, net_h = 2100;
  int net_r, net_c;
  int scale = 20;
  int X, Y;
  float damp_offset;
  
  float[][] amplitudes;
  float phase;
  
  RippleGenerator(int X, int Y)
  {
    this.X = X;
    this.Y = Y;
    
    net_r = net_w/scale;
    net_c = net_h/scale;
    
    amplitudes = new float[net_r][net_c];
    
    frameRate(100);
  }
  
  void calculate_ripple()
  {
    phase -= 0.2;
    
    
    for(int y = 0; y< net_r; y++)  {
      
      for(int x = 0; x < net_c ; x++)  {
        
                float r = sqrt((X-x)*(X-x) + (Y-y)*(Y-y)) ; 
                //try{fake_damp_offset = map(10/(r), 0, 10, 0, 5);}catch(Exception e){fake_damp_offset = 1;}
                damp_offset  = exp(-0.08*r);
                // damp_offset = 1;
                
                amplitudes[y][x] = 30 * damp_offset * sin(r + phase) ;
        
          }
      
    }
    
  }
  
  void create_mesh()
  {
    background(0);
   noFill();
   stroke(130, 130, 255);
  
  
  translate(width/2, height/2);
  rotateX(PI/3);
  
  translate(-net_w/3, -net_h/3);
  
  
  for(int y = 0; y < net_r -1; y++) {
    
    beginShape(TRIANGLE_STRIP);
    
    for(int x = 0;x < net_c; x++) {
            
            vertex(x*scale, y*scale, amplitudes[y][x]);
            vertex(x*scale, (y + 1)*scale, amplitudes[y+1][x]);
      
    }
    endShape();
  }
  }
  
}
