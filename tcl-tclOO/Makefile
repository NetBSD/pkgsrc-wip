# $NetBSD: Makefile,v 1.8 2013/11/16 14:41:09 mwilhelmy Exp $
#

DISTNAME=	TclOO1.0.1
PKGNAME=	${DISTNAME:S/TclOO/tcl-tclOO-/}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=tcl/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.tcl.tk/
COMMENT=	Core for other TCL OO extensions and basic TCL OO framework
LICENSE=	2-clause-bsd # with custom, non-effective terms, same as Tcl

GNU_CONFIGURE=	yes

# Note: TclOO is included in Tcl8.6, delete this package after pkgsrc bumps Tcl
CONFLICTS=	tcl-9* tcl-8.[6-9].*

SUBST_CLASSES+=			manpages
SUBST_STAGE.manpages=	post-patch
SUBST_MESSAGE.manpages=	Fixing manual pages
SUBST_FILES.manpages=	doc/*.[3n]
SUBST_SED.manpages=		-e "/^\\.so /d"

pre-install:
	${MV} ${WRKSRC}/doc/class.n ${WRKSRC}/doc/tclOO-class.n

.include "../../lang/tcl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
