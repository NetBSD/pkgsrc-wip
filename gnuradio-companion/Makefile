# $NetBSD: Makefile,v 1.4 2014/09/28 00:40:28 makoto Exp $

PKGNAME=	gnuradio-companion-${VERSION}
COMMENT=	Gnuradio-companion, user interface entry

CONF_FILES+=	${EGDIR}/grc.conf	${PKG_SYSCONFDIR}/grc.conf

DEPENDS+=	${PYPKGPREFIX}-lxml-[0-9]*:../../textproc/py-lxml/

.include	"../../wip/gnuradio-core/Makefile.common"
.include	"../../wip/gnuradio-core/Nocore.mk"

# gnuradio-companion
CMAKE_ARGS+=	-DENABLE_DEFAULT=OFF
CMAKE_ARGS+=	-DENABLE_GRC=ON

.include	"../../x11/py-gtk2/buildlink3.mk"
.include	"../../mk/bsd.pkg.mk"

# -- Configuring gnuradio-companion support...
# --   Dependency ENABLE_GNURADIO_RUNTIME = ON
# --   Dependency ENABLE_PYTHON = ON
# --   Dependency PYTHON_MIN_VER_FOUND = TRUE
# --   Dependency CHEETAH_FOUND = TRUE
# --   Dependency LXML_FOUND = TRUE
# --   Dependency PYGTK_FOUND = TRUE
# --   Dependency NUMPY_FOUND = TRUE
# --   Enabling gnuradio-companion support.
# --   Override with -DENABLE_GRC=ON/OFF
