# $NetBSD: Makefile,v 1.4 2012/10/22 21:33:11 othyro Exp $
#

DISTNAME=	itcl3.4.1
PKGNAME=	${DISTNAME:S/itcl/tcl85-itcl-/}
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://sourceforge.net/projects/incrtcl/files/%5BIncr%20Tcl_Tk%5D-source/3.4.1/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://incrtcl.sourceforge.net/
COMMENT=	O-O system for Tcl
LICENSE=	2-clause-bsd # ?

GNU_CONFIGURE=	yes

pre-install:
		${MV} ${WRKSRC}/doc/class.n ${WRKSRC}/doc/itcl-class.n

.include "../../x11/tk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
