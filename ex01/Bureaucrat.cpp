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
#include "Form.hpp"

/* Exceptions implementations */

Bureaucrat::GradeTooHighException::GradeTooHighException(std::string const msg) : _msg(msg) {}
Bureaucrat::GradeTooHighException::~GradeTooHighException() throw() {}

const char *	Bureaucrat::GradeTooHighException::what() const throw()
{return (_msg.c_str());}

Bureaucrat::GradeTooLowException::GradeTooLowException(std::string const msg) : _msg(msg) {}
Bureaucrat::GradeTooLowException::~GradeTooLowException() throw() {}

const char *	Bureaucrat::GradeTooLowException::what() const throw()
{return (_msg.c_str());}

/* Bureaucrat implementations */

Bureaucrat::Bureaucrat ( void ) : _name("default"), _grade(150) {}

Bureaucrat::Bureaucrat ( std::string const name, int const grade ) : _name(name), _grade(grade)
{
	if (grade > 150)
	{
		throw GradeTooLowException(ERROR + _name + BUREAUCRAT_TOO_LOW);
		return ;
	}

	if (grade < 1) {
		throw GradeTooHighException(ERROR + _name + BUREAUCRAT_TOO_HIGH);
		return ;
	}
}

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


const std::string Bureaucrat::getName ( void )
{return (_name);}

int	Bureaucrat::getGrade ( void ) 
{return (_grade);}

void	Bureaucrat::promotion ( void )
{
	if (_grade - 1 < 1) {
		throw GradeTooHighException(ERROR + PROMOTION_FAIL + _name + BUREAUCRAT_TOO_HIGH1);
		return ;
	}
	_grade--;
}

void	Bureaucrat::demotion ( void )
{
	if (_grade + 1 > 150) {
		throw GradeTooLowException(ERROR + DEMOTE_FAIL + _name + BUREAUCRAT_TOO_LOW1);
		return ;
	}
	_grade++;
}

void	Bureaucrat::put_grade ( int newGrade ) 
{
	if (newGrade < 1) {
		throw GradeTooHighException(ERROR + CHANGE_GRADE_FAIL + BUREAUCRAT_TOO_HIGH);
		return ;
	}
	if (newGrade > 150) {
		throw GradeTooLowException(ERROR + CHANGE_GRADE_FAIL + BUREAUCRAT_TOO_LOW);
		return ;
	}
	_grade = newGrade;
}

void	Bureaucrat::signForm ( Form & form )
{
	try {
		form.beSigned( *this );
	}
	catch (std::exception& e) {
		std::cout << _name << " couldn't sign " << form.getName() << " because " << e.what() << std::endl;
	}
}