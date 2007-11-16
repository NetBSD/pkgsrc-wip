# $NetBSD: Makefile,v 1.8 2007/11/16 15:43:57 hoka_adam Exp $
#

DISTNAME=		slocate-2.7
CATEGORIES=		sysutils
MASTER_SITES=		http://slocate.trakker.ca/files/

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://slocate.trakker.ca/
COMMENT=		Secure Locate

PKG_INSTALLATION_TYPES=	overwrite pkgviews

GNU_CONFIGURE=		YES
USE_TOOLS+=		gmake
CONFIGURE_ARGS+=	--datadir=${PREFIX}/var
CONFIGURE_ARGS+=	--sysconfdir=${PREFIX}/etc

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1
MANCOMPRESSED=		yes

SLOCATE_GROUP?=		slocate
PKG_GROUPS=			${SLOCATE_GROUP}
PKG_GROUPS_VARS+=	SLOCATE_GROUP

OWN_DIRS=			${PREFIX}/var/slocate
OWN_DIRS_PERMS+=	${PREFIX}/var/slocate ${ROOT_USER} ${SLOCATE_GROUP} 0750

pre-configure:
.for f in aclocal.m4 Makefile.in configure stamp-h.in
	${TOUCH} ${WRKSRC}/$f
.endfor

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/slocate ${PREFIX}/bin/
	${CHOWN} ${ROOT_USER}:${SLOCATE_GROUP} ${PREFIX}/bin/slocate
	${CHMOD} 2755 ${PREFIX}/bin/slocate
	${LN} -f -s ${PREFIX}/bin/slocate ${PREFIX}/bin/locate
	${LN} -f -s ${PREFIX}/bin/slocate ${PREFIX}/bin/updatedb
	${INSTALL_MAN} ${WRKSRC}/doc/updatedb.1.gz \
		${PREFIX}/${PKGMANDIR}/man1/updatedb.1.gz
	${INSTALL_MAN} ${WRKSRC}/doc/slocate.1.other.gz \
		${PREFIX}/${PKGMANDIR}/man1/slocate.1.gz
	${LN} -f -s ${PREFIX}/${PKGMANDIR}/man1/slocate.1.gz \
		${PREFIX}/${PKGMANDIR}/man1/locate.1.gz

.include "../../mk/bsd.pkg.mk"
