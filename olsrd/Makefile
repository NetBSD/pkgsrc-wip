# $NetBSD: Makefile,v 1.3 2009/09/06 23:06:47 khorben Exp $
#

DISTNAME=	olsrd-0.5.6-r5
PKGNAME=	olsrd-0.5.6r5
CATEGORIES=	net
MASTER_SITES=	http://www.olsr.org/releases/0.5/

MAINTAINER=	khorben@defora.org
HOMEPAGE=	http://www.olsr.org/
COMMENT=	Ad-hoc wireless mesh routing daemon

LICENSE=	modified-bsd

PKG_DESTDIR_SUPPORT=	user-destdir
USE_TOOLS+=	bison
USE_TOOLS+=	gmake

MAKE_FLAGS+=ETCDIR=${DESTDIR}${PREFIX}/etc
MAKE_FLAGS+=EXTRA_CPPFLAGS=-DETCDIR=\\\"${PREFIX}/etc\\\"

EGDIR=	${PREFIX}/share/examples/olsrd
CONF_FILES=	${EGDIR}/olsrd.conf ${PREFIX}/etc/olsrd.conf
INSTALLATION_DIRS=	${EGDIR}

post-install:
	${INSTALL_DATA} ${WRKSRC}/files/olsrd.conf.default.lq		\
		${DESTDIR}${EGDIR}/olsrd.conf

.include "../../mk/bsd.pkg.mk"
