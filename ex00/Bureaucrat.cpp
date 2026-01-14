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

Bureaucrat::Bureaucrat ( void ) : _name("default"), _grade(1) {}

Bureaucrat::Bureaucrat ( const Bureaucrat & src ) : _name(src._name), _grade(src._grade) {}

Bureaucrat::~Bureaucrat ( void ) {}

Bureaucrat & Bureaucrat::operator= ( const Bureaucrat & src ) {
	if ( this != &src ) {
		_grade = src._grade;
	}
	return ( *this );
}

std::ostream &	operator<< ( std::ostream & out, Bureaucrat & src ) {
	out << src.getName() << ", bureaucrat grade " << src.getGrade();
	return (out);
}


const std::string Bureaucrat::getName ( void ) {
	return (_name);
}

int	Bureaucrat::getGrade ( void ) {
	return (_grade);
}

void	Bureaucrat::promotion ( void ) {
	_grade--;
}

void	Bureaucrat::demotion ( void ) {
	_grade++;
}

void	Bureaucrat::put_grade ( int newGrade ) {
	_grade = newGrade;
}