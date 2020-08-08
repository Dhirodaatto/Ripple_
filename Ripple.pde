import peasy.*;

RippleGenerator gen;
PeasyCam cam;

float[][] offset;

void setup()
{
  size(1920, 1080, P3D);
  cam = new PeasyCam(this, 1000, 220, 1000, 700); 
  gen = new RippleGenerator(52, 40);
}

void draw()
{
  gen.calculate_ripple();
  gen.create_mesh();
}
