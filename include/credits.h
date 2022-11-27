#ifndef CREDITS_H
#define CREDITS_H

#include "state.h"
#include <sstream>;
using std::stringstream;
using std::getline;

class Credits : public State
{
   private:
      virtual bool LoopCondition() override;

   public:
       Credits(SDLChessGame* parent);
       virtual ~Credits();

       void enter();
       void leave();
       virtual void Render() override;
       virtual void HandleInput() override;
};

#endif
