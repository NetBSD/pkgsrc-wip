# $NetBSD: Makefile,v 1.10 2011/04/03 02:48:41 ishit Exp $

DISTNAME=	mathopd-1.5p6
CATEGORIES=	www
MASTER_SITES=	http://www.mathopd.org/dist/

MAINTAINER=	ishit@users.sourceforge.net
HOMEPAGE=	http://www.mathopd.org/
COMMENT=	Very small, yet very fast HTTP server

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../mk/bsd.prefs.mk"

BUILD_DEFS=	VARBASE MATHOPD_USER MATHOPD_GROUP

MATHOPD_USER?=		mathopd
MATHOPD_GROUP?=		mathopd
PKG_USERS_VARS+=	MATHOPD_USER
PKG_GROUPS_VARS+=	MATHOPD_GROUP

WRKSRC=		${WRKDIR}/${DISTNAME}/src
EGDIR=		${PREFIX}/share/examples/mathopd
DOCDIR=		${PREFIX}/share/doc/mathopd
CONF_FILES=	${EGDIR}/mathopd.conf ${PKG_SYSCONFDIR}/mathopd.conf
RCD_SCRIPTS=	mathopd

MAKE_DIRS=		${VARBASE}/log/mathopd
OWN_DIRS_PERMS+=	${VARBASE}/log/mathopd ${MATHOPD_USER} ${MATHOPD_GROUP} 0755

PKG_GROUPS=	${MATHOPD_GROUP}
PKG_USERS=	${MATHOPD_USER}:${MATHOPD_GROUP}::mathopd\ user

DOCS=	CHANGES cgi.txt config.txt running.txt sample.cfg syntax.txt

SUBST_CLASSES+=			fix-paths
SUBST_STAGE.fix-paths=		pre-configure
SUBST_MESSAGE.fix-paths=	Fixing absolute paths.
SUBST_FILES.fix-paths=		Makefile
SUBST_FILES.fix-paths+=		../doc/sample.cfg
SUBST_SED.fix-paths=		-e 's,/usr/local,${PREFIX},g'
SUBST_SED.fix-paths+=		-e 's,/var/mathopd/pid,${VARBASE}/run/mathopd.pid,g'
SUBST_SED.fix-paths+=		-e 's,/var/mathopd/log,${VARBASE}/log/mathopd/access_log,g'
SUBST_SED.fix-paths+=		-e 's,/var/mathopd/errorlog,${VARBASE}/log/mathopd/error_log,g'
SUBST_SED.fix-paths+=		-e 's,/var/mathopd/childlog,${VARBASE}/log/mathopd/child_log,g'
SUBST_SED.fix-paths+=		-e 's,/home/boland/\*,${PREFIX}/share/httpd/htdocs/\*,g'
SUBST_SED.fix-paths+=		-e 's,/home/boland/cgi-bin,${PREFIX}/libexec/cgi-bin,g'

.if ${OPSYS} == "NetBSD"
CPPFLAGS+=	-DHAVE_VFORK
.endif

.if ${OPSYS} == "Linux"
BUILD_DEFS+=	EXTRA_OBJS
CPPFLAGS+=	-DHAVE_CRYPT_H
CPPFLAGS+=	-DLINUX_SENDFILE
CPPFLAGS+=	-D_FILE_OFFSET_BITS=64
EXTRA_OBJS+=	sendfile.o
.endif

.if ${OPSYS} == "FreeBSD"
BUILD_DEFS+=	EXTRA_OBJS
CPPFLAGS+=	-DFREEBSD_SENDFILE
EXTRA_OBJS+=	sendfile.o
.endif

.if ${OPSYS} == "SunOS"
CPPFLAGS+=	-D_FILE_OFFSET_BITS=64
CPPFLAGS+=	-DHAVE_CRYPT_H
.endif

pre-configure:
.if ${OPSYS} == "SunOS"
	${MV} ${WRKSRC}/Makefile ${WRKSRC}/Makefile.patched
	${SED} -e 's!LIBS = -lcrypt!LIBS = -lsocket -lnsl -lresolv!' \
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
