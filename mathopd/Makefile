# $NetBSD: Makefile,v 1.4 2005/04/17 16:53:58 ishit Exp $

DISTNAME=	mathopd-1.5p5
CATEGORIES=	www
MASTER_SITES=	http://www.mathopd.org/dist/

MAINTAINER=	ishit@users.sourceforge.jp
HOMEPAGE=	http://www.mathopd.org/
COMMENT=	Very small, yet very fast HTTP server

USE_PKGINSTALL=	yes

MATHOPD_GROUP=	www
MATHOPD_USER=	www

.include "../../mk/bsd.prefs.mk"

WRKSRC=		${WRKDIR}/${DISTNAME}/src
EGDIR=		${PREFIX}/share/examples/mathopd
DOCDIR=		${PREFIX}/share/doc/mathopd
CONF_FILES=	${EGDIR}/mathopd.conf ${PKG_SYSCONFDIR}/mathopd.conf
RCD_SCRIPTS=	mathopd

MAKE_DIRS=	${PREFIX}/share/mathopd
OWN_DIRS_PERMS+=	${VARBASE}/log/mathopd ${MATHOPD_USER} ${MATHOPD_GROUP} 0755

PKG_GROUPS=	${MATHOPD_GROUP}
PKG_USERS=	${MATHOPD_USER}:${MATHOPD_GROUP}::mathopd\\ user

DOCS=	CHANGES cgi.txt config.txt running.txt sample.cfg syntax.txt

.if ${OPSYS} == "NetBSD"
CPPFLAGS+=	-DHAVE_VFORK
.endif

.if ${OPSYS} == "Linux"
CPPFLAGS+=	-DHAVE_CRYPT_H
CPPFLAGS+=	-DLINUX_SENDFILE
.endif

.if ${OPSYS} == "FreeBSD"
CPPFLAGS+=	-DFREEBSD_SENDFILE
.endif

.if ${OPSYS} == "SunOS"
CPPFLAGS+=	-DNEED_INET_ATON
CPPFLAGS+=	-DHAVE_CRYPT_H
.endif

pre-configure:
.if ${OPSYS} == "SunOS"
	@${MV} ${WRKSRC}/Makefile ${WRKSRC}/Makefile.patched
	@${SED} -e 's!LDADD=	-lcrypt!LDADD=	-lsocket -lnsl!' \
	< ${WRKSRC}/Makefile.patched \
	> ${WRKSRC}/Makefile
.endif
.if ${OPSYS} == "Linux" || ${OPSYS} == "FreeBSD"
	@${MV} ${WRKSRC}/Makefile ${WRKSRC}/Makefile.patched
	@${SED} -e 's!util.c stub.c!util.c sendfile.c stub.c!' \
	< ${WRKSRC}/Makefile.patched \
	> ${WRKSRC}/Makefile
.endif

pre-install:
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA_DIR} ${DOCDIR}

post-install:
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/doc/sample.cfg ${EGDIR}/mathopd.conf

	${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/COPYING ${DOCDIR}
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/README  ${DOCDIR}
	for df in ${DOCS}; do	\
		${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/doc/$${df}  ${DOCDIR};	\
	done

	${TOUCH} ${VARBASE}/run/mathopd.pid
	${CHOWN} ${MATHOPD_USER}:${MATHOPD_GROUP} ${VARBASE}/run/mathopd.pid

.include "../../mk/bsd.pkg.mk"
