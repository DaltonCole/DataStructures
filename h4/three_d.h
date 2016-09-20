//Dalton Cole
//Class and section: CS153, A 
//Date: 3/26/14
//Description: three Dementional package for abstractpackage.h

#ifndef THREE_H
#define THREE_H

#include "abstractpackage.h"

const float volume_rate = .02;  //rate of 3D packages
const float weight_rate = 2.71; //rate of 3D package weight

class three_d : public AbstractPackage
{
  private:
    float m_length; //the length of the package
    float m_width;  //the width of the package
    float m_height; //the height of the package
    float m_weight; //the weight of the package
    float m_charge; //total charge of package

  public:
  // Purpose: Constructor
  // -- INLINE
  three_d(string f, string t, float l, float w, float h, float m) :
   AbstractPackage(f,t), m_length(l), m_width(w), m_height(h), m_weight(m),
    m_charge((l*w*h*volume_rate)+(m*weight_rate)){}

  // Purpose: Returns the charge of a package.
  // -- VIRTUAL
  virtual float getCharge() const {return m_charge;}

  // Purpose: Returns the package's sender.
  // -- VIRTUAL
  virtual string getFrom() const {return m_from;}

  // Purpose: Returns the package's receiver.
  // -- VIRTUAL
  virtual string getTo() const {return m_to;}

  // Purpose: Destructor
  // -- Inline
  virtual ~three_d() {}
	
};

#endif
