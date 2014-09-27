# $NetBSD: Makefile,v 1.4 2014/09/27 08:17:45 makoto Exp $

PKGNAME=	gnuradio-utils-${VERSION}
COMMENT=	Utilities in GNU Radio

.include	"../../wip/gnuradio-core/Makefile.common"
.include	"../../wip/gnuradio-core/Nocore.mk"

DEPENDS+=	${PYPKGPREFIX}-matplotlib-[0-9]*:../../graphics/py-matplotlib
CONF_FILES+=	${EGDIR}/modtool.conf	${PKG_SYSCONFDIR}/modtool.conf

CMAKE_ARGS+=	-DENABLE_DEFAULT=False
CMAKE_ARGS+=	-DENABLE_GR_UTILS=True

.include        "../../devel/SDL/buildlink3.mk"

.include	"../../mk/bsd.pkg.mk"
