# $NetBSD: Makefile,v 1.3 2012/10/14 13:30:45 thomasklausner Exp $
#

DISTNAME=	TclOO0.6
PKGNAME=	${DISTNAME:S/TclOO/tcl-tclOO-/}
CATEGORIES=	devel
MASTER_SITES=	http://sourceforge.net/projects/tcl/files/TclOO%20Package/0.6/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.tcl.tk/
COMMENT=	Core for other TCL OO extensions and basic TCL OO framework
#LICENSE=	# TODO: (see mk/license.mk)

GNU_CONFIGURE=	yes

CONFIGURE_ARGS+=	--with-tcl=${BUILDLINK_PREFIX.tcl}/lib/tcl8.5

.include "../../lang/tcl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
