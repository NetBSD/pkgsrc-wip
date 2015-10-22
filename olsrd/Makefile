# $NetBSD: Makefile,v 1.6 2012/10/03 21:32:46 asau Exp $
#

DISTNAME=	olsrd-0.6.8
CATEGORIES=	net
MASTER_SITES=	http://www.olsr.org/releases/0.6/

MAINTAINER=	khorben@defora.org
HOMEPAGE=	http://www.olsr.org/
COMMENT=	Ad-hoc wireless mesh routing daemon

LICENSE=	modified-bsd

USE_TOOLS+=	bison
USE_TOOLS+=	flex
USE_TOOLS+=	gmake

.include "../../mk/bsd.prefs.mk"

MAKE_FLAGS+=ETCDIR=${DESTDIR}${PREFIX}/etc
MAKE_FLAGS+=MANDIR=${DESTDIR}${PREFIX}/${PKGMANDIR}
MAKE_FLAGS+=SBINDIR=${DESTDIR}${PREFIX}/sbin
MAKE_FLAGS+=EXTRA_CPPFLAGS=-DETCDIR=\\\"${PREFIX}/etc\\\"

EGDIR=	${PREFIX}/share/examples/olsrd
CONF_FILES=	${EGDIR}/olsrd.conf ${PREFIX}/etc/olsrd/olsrd.conf
INSTALLATION_DIRS=	${EGDIR}

post-install:
	${INSTALL_DATA} ${WRKSRC}/files/olsrd.conf.default.lq		\
		${DESTDIR}${EGDIR}/olsrd.conf
	${RM} ${DESTDIR}${PREFIX}/etc/olsrd.conf

.include "../../mk/bsd.pkg.mk"
