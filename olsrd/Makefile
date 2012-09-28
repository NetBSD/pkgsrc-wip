# $NetBSD: Makefile,v 1.5 2012/09/28 22:44:11 khorben Exp $
#

DISTNAME=	olsrd-0.6.1
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://www.olsr.org/releases/0.6/

MAINTAINER=	khorben@defora.org
HOMEPAGE=	http://www.olsr.org/
COMMENT=	Ad-hoc wireless mesh routing daemon

LICENSE=	modified-bsd

PKG_DESTDIR_SUPPORT=	user-destdir
USE_TOOLS+=	bison
USE_TOOLS+=	flex
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
