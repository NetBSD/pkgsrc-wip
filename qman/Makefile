# $NetBSD$

DISTNAME=	qman-1.5.1
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=plp13/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/plp13/qman/
COMMENT=	Modern man page viewer
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-cogapp-[0-9]*:../../devel/py-cogapp

USE_TOOLS+=	pkg-config

MESON_ARGS+=	-Dtests=disabled
MESON_ARGS+=	-Dconfigdir=${PKG_SYSCONFDIR}

EGDIR=			share/examples/qman
INSTALLATION_DIRS+=	${EGDIR} ${EGDIR}/themes

OWN_DIRS+=	${PKG_SYSCONFDIR}/themes
CONFIGS+=	qman.conf
CONFIGS+=	themes/adwaita-light.conf
CONFIGS+=	themes/adwaita.conf
CONFIGS+=	themes/catppuccin_latte.conf
CONFIGS+=	themes/modernity-light.conf
CONFIGS+=	themes/modernity.conf
.for f in ${CONFIGS}
CONF_FILES+=	${EGDIR}/${f} ${PKG_SYSCONFDIR}/${f}
.endfor

.include "../../mk/bsd.fast.prefs.mk"

pre-configure:
	${LN} -s ${PREFIX}/bin/cog-${PYVERSSUFFIX} ${BUILDLINK_DIR}/bin/cog
.if ${OPSYS} == NetBSD || ${OPSYS} == FreeBSD
	${ECHO} "[misc]" > ${WRKSRC}/config/qman.conf
	${ECHO} "system_type=freebsd" >> ${WRKSRC}/config/qman.conf
.endif

post-install:
.for f in ${CONFIGS}
	${MV} ${DESTDIR}${PKG_SYSCONFDIR}/${f} ${DESTDIR}${PREFIX}/${EGDIR}/${f}
.endfor

.include "../../lang/python/pyversion.mk"
.include "../../devel/meson/build.mk"
.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
