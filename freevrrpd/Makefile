# $NetBSD$

GITHUB_PROJECT=	FreeVRRPd
DISTNAME=	freevrrpd-1.1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=gvnn3/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

#https://github.com/gvnn3/FreeVRRPd/archive/v0.9.3.tar.gz
#https://github.com/gvnn3/FreeVRRPd/archive/v1.1.zip

MAINTAINER=	spe@phear.org
COMMENT=	BSD licensed implementation of the VRRP protocol (V2 and V3)

#MAKE_ENV+=	PTHREAD_CFLAGS=${PTHREAD_CFLAGS:Q}
#MAKE_ENV+=	PTHREAD_LIBS=${PTHREAD_LIBS:Q}

#INSTALLATION_DIRS=	bin ${PKGMANDIR}/man8 share/examples/rc.d
#
#do-install:
#	${INSTALL_PROGRAM} ${WRKSRC}/freevrrpd ${DESTDIR}${PREFIX}/sbin
#	${INSTALL_DATA} ${WRKSRC}/freevrrpd.conf.sample ${DESTDIR}${PREFIX}/share/examples
#	${INSTALL_SCRIPT} ${FILESDIR}/freevrrpd.sh ${DESTDIR}${PREFIX}/share/examples/rc.d
#	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.8 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man8

.include "../../mk/bsd.pkg.mk"
