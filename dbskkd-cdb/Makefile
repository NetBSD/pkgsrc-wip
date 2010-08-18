# $NetBSD: Makefile,v 1.2 2010/08/18 22:08:36 ryo-on Exp $
#

DISTNAME=	dbskkd-cdb-2.00
CATEGORIES=	inputmethod japanese
MASTER_SITES=	http://dbskkd-cdb.googlecode.com/files/

MAINTAINER=	ryo_on@yk.rim.or.jp
HOMEPAGE=	http://github.com/jj1bdx/dbskkd-cdb
COMMENT=	SKK dictionary server based on cdb
LICENSE=	gnu-gpl-v3

PKG_DESTDIR_SUPPORT=	user-destdir

DOCSDIR=		${PREFIX}/share/doc/${PKGBASE}
INSTALLATION_DIRS=	libexec \
			${DOCSDIR} \
			bin

DEPENDS=	skk-jisyo-cdb-[0-9]*:../../wip/skk-jisyo-cdb

SUBST_CLASSES+=			fix-paths
SUBST_STAGE.fix-paths=		pre-configure
SUBST_MESSAGE.fix-paths=	fixing pathes
SUBST_FILES.fix-paths=		dbskkd-cdb.c
SUBST_SED.fix-paths=		-e 's,/usr/local/share/skk/SKK-JISYO.L.cdb,${PREFIX}/share/skk/SKK-JISYO.L.cdb,g'


MAKE_FLAGS+=		CDBLIB=${BUILDLINK_DIR}/lib/libcdb.a
MAKE_FLAGS+=		INSTALLDIR=${DESTDIR}${PREFIX}/libexec

INSTALL_DOCS=	CHANGES \
		LICENSE	\
		README \
		READMEJP \
		example-daemontools.txt \
		example-inetd.txt \
		skk-server-protocol.txt

INSTALL_SCRIPTS=	makeskkcdb.sh \
			skktocdbm.sh

post-install:
.for filename in ${INSTALL_DOCS}
	${INSTALL_DATA} ${WRKSRC}/${filename} ${DESTDIR}/${DOCSDIR}
.endfor
.for filename in ${INSTALL_SCRIPTS}
	${INSTALL_SCRIPT} ${WRKSRC}/${filename} ${DESTDIR}${DOCSDIR}
.endfor

.include "../../databases/tinycdb/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
