# $NetBSD: Makefile,v 1.1.1.1 2007/05/31 02:30:17 hoka_adam Exp $
#

DISTNAME=	lua-5.0.3
CATEGORIES=	lang
MASTER_SITES=   ftp://ftp.tecgraf.puc-rio.br/pub/lua/ \
                ftp://ftp.ntua.gr/pub/lang/lua/ \
		ftp://ftp.gwdg.de/pub/languages/lua/ \
		ftp://ftp.u-aizu.ac.jp/pub/lang/lua/ \
		ftp://ftp.ucore.com/lua/dist/ \
		ftp://sunsite.dk/pub/languages/lua/ \
		ftp://ftp.chg.ru/pub/lang/lua/ \
		http://www.lua.org/ftp/ \
		http://www.tecgraf.puc-rio.br/lua/ftp/ \
		http://ftp.gwdg.de/pub/languages/lua/ \
		http://mirrors.sunsite.dk/lua/ \
		http://ftp.chg.ru/pub/lang/lua/


MAINTAINER=	adam.hoka@gmail.com
HOMEPAGE=	http://www.lua.org/
COMMENT=	Lua legacy package

CONFLICTS=      lua-5.1>=

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LANGUAGES=	c

USE_LIBTOOL=	yes
#USE_TOOLS+=	gmake

MAKE_ENV+=      MYCFLAGS=${CFLAGS:Q}
MAKE_ENV+=      MYLDFLAGS=${LDFLAGS:Q}\ ${LIBS:Q}
MAKE_ENV+=      DLLIB=${BUILDLINK_LDADD.dl:Q}

DOCDIR=         ${PREFIX}/share/doc/lua
EGDIR=          ${PREFIX}/share/examples/lua

# fixing the hardcoded tools and prefix.
SUBST_CLASSES+=                 fix-conf
SUBST_STAGE.fix-conf=    pre-configure
SUBST_MESSAGE.fix-conf=  Fixing absolute paths.
SUBST_FILES.fix-conf=    config
SUBST_SED.fix-conf=      -e "s:/usr/local:${PREFIX}:g"
SUBST_SED.fix-conf+=     -e "s:gcc:${CC}:g"
SUBST_SED.fix-conf+=     -e "s:cp:${CP}:g"
SUBST_SED.fix-conf+=     -e "s:strip:${STRIP}:g"
SUBST_SED.fix-conf+=     -e "s:INSTALL_EXEC= cp:${INSTALL_PROGRAM}:g"
SUBST_SED.fix-conf+=     -e "s:INSTALL_DATA= cp:${INSTALL_DATA}:g"

post-build:
	cd ${WRKSRC}/etc && ${SETENV} ${MAKE_ENV} ${MAKE} bin2c

post-install:
	${INSTALL_DATA_DIR} ${DOCDIR}
	set -e; \
	cd ${WRKSRC}; for f in README COPYRIGHT HISTORY; do		\
		${INSTALL_DATA} "$$f" ${DOCDIR};			\
	done
	set -e; \
	cd ${WRKSRC}/doc; for f in *.html *.gif; do			\
		${INSTALL_DATA} "$$f" ${DOCDIR};			\
	done
	${INSTALL_DATA_DIR} ${EGDIR}
	set -e; \
	cd ${WRKSRC}/test; for f in README *.lua; do			\
		${INSTALL_DATA} "$$f" ${EGDIR};				\
	done
	${INSTALL_DATA_DIR} ${EGDIR}/etc
	set -e; \
	cd ${WRKSRC}/etc; for f in README *.c *.h *.lua lua.magic lua.xpm; do \
		${INSTALL_DATA} "$$f" ${EGDIR}/etc;			\
	done
	${INSTALL_PROGRAM} ${WRKSRC}/etc/bin2c ${PREFIX}/bin

# FIXME: I don`t know if dlopen is needed:
#.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
