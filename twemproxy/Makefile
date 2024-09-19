# $NetBSD$

GITHUB_PROJECT=	twemproxy
DISTNAME=	v0.4.1
PKGNAME=	${GITHUB_PROJECT}-${DISTNAME}
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_GITHUB:=twitter/}
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	gianni-pkgsrc-wip@daprile.net
HOMEPAGE=	https://github.com/twitter/twemproxy/
COMMENT=	Fast, light-weight proxy for memcached and redis
LICENSE=	apache-2.0

EGFILES=		conf/nutcracker.yml
EGFILES+=		conf/nutcracker.leaf.yml conf/nutcracker.root.yml
EGDIR=			share/examples/twemproxy
INSTALLATION_DIRS=	${EGDIR}

GNU_CONFIGURE=	YES
USE_LIBTOOL=	yes
USE_TOOLS+=	autoreconf automake m4

WRKSRC=	${WRKDIR}/twemproxy-0.4.1

CONF_FILES+=	${EGDIR}/nutcracker.yml ${PKG_SYSCONFDIR}/nutcracker.yml
CONF_FILES+=	${EGDIR}/nutcracker.root.yml ${EG_DIR}/nutcracker.leaf.yml

pre-configure:
	cd ${WRKSRC} && autoreconf -fvi

post-install:
.for f in ${EGFILES}
	${INSTALL_DATA} ${WRKSRC}/${f} \
		${DESTDIR}${PREFIX}/${EGDIR}/`basename ${f}`
.endfor

.include "../../devel/libexecinfo/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
