#include "llvm/Pass.h"
#include "llvm/IR/Function.h"
#include "llvm/Support/raw_ostream.h"
#include <map>

using namespace llvm;



namespace {
  
struct CountOpcode : public FunctionPass {


    std::map<std::string, int> opCounter;


    static char ID;

    CountOpcode() : FunctionPass(ID) {}


    virtual bool runOnFunction(Function &F)
    {

            errs() << "Function Name: " << F.getName() << "\n \n";   

            for(auto Block = F.begin(); Block != F.end();  Block++)
            {

                    for(auto  Instruction =  Block->begin(); Instruction != Block->end(); Instruction++) {                   
                        
                        if(opCounter.find(Instruction->getOpcodeName()) == opCounter.end()){
                         
                            opCounter[Instruction->getOpcodeName()] =  1; 
                       
                        }else
                        {                      
                      
                           opCounter[Instruction->getOpcodeName()]++; 
                        }
                           
                    } 
            }

            for(auto &[OpcodeName , NumOpcodes] : opCounter)
            { 
                    errs() << "Opcode Name: " << "[ "<< OpcodeName << " ]" << '\n';
                    errs() << "Num of Opcodes: " << NumOpcodes << '\n';
                    errs() << "-------------------------------------------" << '\n';
            }

           return false;

    }



};

}

char CountOpcode::ID = 0;
static RegisterPass<CountOpcode> X("CountOpcode", "Count the number of opcodes for each function");
