# $NetBSD: Makefile,v 1.4 2012/10/22 21:45:24 othyro Exp $
#

DISTNAME=	TclOO0.6
PKGNAME=	${DISTNAME:S/TclOO/tcl-tclOO-/}
CATEGORIES=	devel
MASTER_SITES=	http://sourceforge.net/projects/tcl/files/TclOO%20Package/0.6/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.tcl.tk/
COMMENT=	Core for other TCL OO extensions and basic TCL OO framework
LICENSE=	2-clause-bsd # ?

GNU_CONFIGURE=	yes

.include "../../lang/tcl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
