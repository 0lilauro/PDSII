#include "OpacidadeDecorator.hpp"

std::string OpacidadeDecorator::desenha() {
    if (this->_opacidade >= 0  && this->_opacidade <= 1 ) {

        std::string label = "baixa";
        if(this->_opacidade > 0.33 && this->_opacidade <= 0.66) {
            label = "média";
        } else if (this->_opacidade > 0.66) {

            label = "alta";
        }
        return FormaDecorator::desenha() + "\n- opacidade: " + label;
    } else {
        return FormaDecorator::desenha();
    }
}

void OpacidadeDecorator::setOpacidade(double opacidade) {
  this->_opacidade = opacidade;
}

double OpacidadeDecorator::getOpacidade() {
  return this->_opacidade;
}
