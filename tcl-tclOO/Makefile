# $NetBSD: Makefile,v 1.1.1.1 2010/10/20 14:01:23 othyro Exp $
#

DISTNAME=	TclOO0.6
PKGNAME=	${DISTNAME:S/TclOO/tcl-tclOO-/}
CATEGORIES=	devel
MASTER_SITES=	http://sourceforge.net/projects/tcl/files/TclOO%20Package/0.6/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.tcl.tk/
COMMENT=	Core for other TCL OO extensions and basic TCL OO framework
#LICENSE=	# TODO: (see mk/license.mk)

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes

CONFIGURE_ARGS+=	--with-tcl=${BUILDLINK_PREFIX.tcl}/lib/tcl8.5

.include "../../wip/tcl85/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
