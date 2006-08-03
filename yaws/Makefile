# $NetBSD: Makefile,v 1.1.1.1 2006/08/03 11:13:40 bartoszkuzma Exp $
#

PKGVERSION=		1.63

DISTNAME=		yaws-${PKGVERSION}
CATEGORIES=		www
MASTER_SITES=		http://yaws.hyber.org/download/

MAINTAINER=		bartosz@atom.eu.org
HOMEPAGE=		http://yaws.hyber.org/
COMMENT=		HTTP high perfomance 1.1 webserver

SUBST_CLASSES+=		man_path
SUBST_STAGE.man_path=	post-patch
SUBST_FILES.man_path=	man/Makefile
SUBST_SED.man_path=	-e 's,share/,,'

USE_TOOLS+=		gmake
GNU_CONFIGURE=		yes

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}/yaws
CONFIGURE_ARGS+=	--localstatedir=${VARBASE}

EGDIR=			${PREFIX}/share/examples/yaws
CONF_FILES=		${EGDIR}/yaws.conf ${PKG_SYSCONFDIR}/yaws/yaws.conf
RCD_SCRIPTS=		yaws
RCD_SCRIPT_WRK.yaws=	${WRKDIR}/yaws.sh

# Installation of default docroot is performed as simple taring and
# untaring files to installation location. It should remove old *.orig
# files to avoid warnings from pkglint.
post-patch:
	${RM} -f ${WRKSRC}/www/code/Makefile.orig
	${RM} -f ${WRKSRC}/www/shopingcart/Makefile.orig

post-configure:
	${SED} -e "s|@PKG_SYSCONFDIR@|${PKG_SYSCONFDIR}|g" \
		-e "s|@PREFIX@|${PREFIX}|g" \
		-e "s|@VARBASE@|${VARBASE}|g" \
		${FILESDIR}/yaws.conf > ${WRKDIR}/yaws.conf
post-install:
	${INSTALL_DATA_DIR} ${PKG_SYSCONFDIR}/yaws
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA} ${WRKDIR}/yaws.conf ${EGDIR}

.include "../../lang/erlang/buildlink3.mk"
.include "../../mk/bsd.prefs.mk"
.include "../../mk/bsd.pkg.mk"
