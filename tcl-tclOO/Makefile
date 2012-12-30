# $NetBSD: Makefile,v 1.6 2012/12/30 03:11:43 othyro Exp $
#

DISTNAME=	TclOO0.6
PKGNAME=	${DISTNAME:S/TclOO/tcl-tclOO-/}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=tcl/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.tcl.tk/
COMMENT=	Core for other TCL OO extensions and basic TCL OO framework
LICENSE=	2-clause-bsd # ?

GNU_CONFIGURE=	yes

pre-install:
		${MV} ${WRKSRC}/doc/class.n ${WRKSRC}/doc/tclOO-class.n

.include "../../lang/tcl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
