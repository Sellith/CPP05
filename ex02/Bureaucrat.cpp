/* *************************************************************************************************************** */
/*   Bureaucrat.cpp                                                                                                */
/*   By: lvan-bre                                                                   .,                             */
/*                                                                                 okxl                            */
/*                                                                                xkddo                            */
/*                                                                               kkxddo                            */
/*                                                                              lxxddol                            */
/*                                                                              xxdolol.                           */
/*                                                                             :kxdddddl                 .ox,      */
/*                                                                       ..,cdkOOkkkxdddd'      ;o.     ckkd,      */
/*                                                               .,:coxOOOkkkkkkkxxxxxddddo:...lxdl.   ckkxd.      */
/*                                                           ;oxOOOOkkxxkxxxxxxxxxxdddddodddxxxkkxxxdlckkxdd.      */
/*                                                        ,oOOOkkkkxxxdddxdddddddddddddoooooodooddddooooddooc      */
/*                                                      ;kkkkkxxxxxddoooooooooooooooooooooooooollooooooololll      */
/*                                                     oxodddddoooooolllllllolooooollloooollllolllllloooolccl;     */
/*                                                    'x:::cclccllllccccccccccclllclllllllllllllllll     .;;cl;    */
/*                                                    d;c::cc:cc:::;::c:c:cccccclccc:cccclllllll,         .:cl.    */
/*                                                      c;,;:;;::::;;::::c..,cccllcc:c;;:lloodk.                   */
/*                                                        'ooooooooodddxxkkkOOOkOOOOOOc:cclllloo'                  */
/*                                                           .XXXXXXXKKXXXXXXXXXXXXXXXkcccclcccllo                 */
/*                                                                 ,KKKKKXXXXXXXXXXXXK0.  .:ccllclll;.             */
/*                                                                                           .ccccccllc,.          */
/*                                                                                                 :::cl:          */
/*                                                                                                                 */
/* *************************************************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"

Bureaucrat::Bureaucrat ( void ) : _name("John"), _grade(150) {}

Bureaucrat::Bureaucrat ( const std::string name , int grade) : _name(name), _grade(grade) {}

Bureaucrat::Bureaucrat ( const Bureaucrat & src ) : _name(src._name), _grade(src._grade) {}

Bureaucrat::~Bureaucrat ( void ) {}

Bureaucrat & Bureaucrat::operator= ( const Bureaucrat & src ) 
{
	if ( this != &src ) {
		_grade = src._grade;
	}
	return ( *this );
}

std::ostream &	operator<< ( std::ostream & out, Bureaucrat & src ) 
{
	out << src.getName() << ", bureaucrat grade " << src.getGrade();
	return (out);
}


const std::string Bureaucrat::getName ( void ) const
{
	return (_name);
}

int	Bureaucrat::getGrade ( void ) const
{
	return (_grade);
}

void	Bureaucrat::promotion ( void )
{
	_grade--;
}

void	Bureaucrat::demotion ( void )
{
	_grade++;
}

void	Bureaucrat::put_grade ( int newGrade )
{
	_grade = newGrade;
}

void	Bureaucrat::signForm ( AForm & form )
{
	try {
		form.beSigned( *this );
	}
	catch (Bureaucrat::gradeTooHighException& e) {
		std::cout << _name << " couldn't sign " << form.getName() << " because " << e.what() << std::endl;
	}
	catch (Bureaucrat::gradeTooLowException& e) {
		std::cout << _name << " couldn't sign " << form.getName() << " because " << e.what() << std::endl;
	}
	catch (AForm::gradeTooHighException& e) {
		std::cout << _name << " couldn't sign " << form.getName() << " because " << e.what() << std::endl;
	}
	catch (AForm::signGradeTooLowException& e) {
		std::cout << _name << " couldn't sign " << form.getName() << " because " << e.what() << std::endl;
	}
	catch (AForm::formAlreadySigned& e) {
		std::cout << _name << " couldn't sign " << form.getName() << " because " << e.what() << std::endl;
	}
}

void	Bureaucrat::executeForm ( AForm const & form )
{
	try {
		form.execute(*this);
	}

	catch (AForm::formNotSigned& e) {
		std::cout << getName() << " couldn't execute " << form.getName() << " because " << e.what() << std::endl;;
		return ;
	}

	catch (AForm::execGradeTooLowSigned& e) {
		std::cout << getName() << " couldn't execute " << form.getName() << " because " << e.what() << std::endl;;
		return ;
	}

	std::cout << getName() << " executed " << form.getName() << std::endl;
	
	catch (ShrubberyCreationForm::failedToOpenFileException& e) {
		std::cout << e.what() << std::endl;
	}

}