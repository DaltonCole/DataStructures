//Dalton Cole
//Class and section: CS153, A 
//Date: 3/26/14
//Description: Two Dementional package for abstractpackage.h

#ifndef TWO_H
#define TWO_H

#include "abstractpackage.h"

const float area_rate = .05; //rate of 2D packages

class two_d : public AbstractPackage
{
  private:
    float m_length; //the length of the package
    float m_width;  //the width of the package
    float m_charge; //total charge of package

  public:
  // Purpose: Constructor
  // -- INLINE
  two_d(string f, string t, float l, float w) : AbstractPackage(f,t), m_length(l), m_width(w), m_charge(w*l*area_rate) {}

  // Purpose: Returns the charge of a package.
  // -- VIRTUAL
  virtual float getCharge() const {return m_charge;}

  // Purpose: Returns the package's sender.
  // -- VIRTUAL
  virtual string getFrom() const {return m_from;}

  // Purpose: Returns the package's receiver.
  // -- VIRTUAL
  virtual string getTo()const {return m_to;}

  // Purpose: Destructor
  // -- Inline
  virtual ~two_d() {}
};

#endif
