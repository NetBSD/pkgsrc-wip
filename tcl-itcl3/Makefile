# $NetBSD: Makefile,v 1.8 2014/02/22 08:25:04 obache Exp $
#

DISTNAME=	itcl3.4.3
PKGNAME=	tcl-${DISTNAME:S/itcl/itcl3-/}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=incrtcl/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://incrtcl.sourceforge.net/
COMMENT=	Framework for building mega-widgets using [incr Tcl]
LICENSE=	mit # Standard ML of New Jersey Variant

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--x-includes=${BUILDLINK_PREFIX.libX11}/include/X11
CONFIGURE_ARGS+=	--x-libraries=${BUILDLINK_PREFIX.libX11}/lib
CONFIGURE_ARGS+=	--includedir=${PREFIX}/include/itcl3
USE_TOOLS+=		grep

post-install:
.for file in body.n class.n code.n configbody.n delete.n ensemble.n find.n \
	is.n itcl.n itclvars.n local.n scope.n
	${RUN} cd ${DESTDIR}${PREFIX}/man/mann/ && \
		${MV} ${file} itcl3-${file}
.endfor

#.include "../../x11/libXt/buildlink3.mk"
#.include "../../x11/libX11/buildlink3.mk"
#.include "../../mk/dlopen.buildlink3.mk"
.include "../../lang/tcl/buildlink3.mk"
#.include "../../x11/tk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
