# $Id: Makefile,v 1.7 2012/09/28 22:47:15 asau Exp $
# New ports collection makefile for:	freevrrpd
# Date created:				Tue Jan 29 18:44:25 EST 2002
# Whom:					Sebastien Petit <spe@phear.org>

PORTNAME=	freevrrpd
DISTNAME=	freevrrpd-0.9.3
CATEGORIES=	net
PKGREVISION=	1
MASTER_SITES=	http://bmw2002.hexod.net/opensource/

MAINTAINER=	spe@phear.org
COMMENT=	This a VRRP RFC2338 Compliant implementation under FreeBSD

MAKE_ENV+=	PTHREAD_CFLAGS=${PTHREAD_CFLAGS:Q}
MAKE_ENV+=	PTHREAD_LIBS=${PTHREAD_LIBS:Q}

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man8 share/examples/rc.d

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/freevrrpd ${DESTDIR}${PREFIX}/sbin
	${INSTALL_DATA} ${WRKSRC}/freevrrpd.conf.sample ${DESTDIR}${PREFIX}/share/examples
	${INSTALL_SCRIPT} ${FILESDIR}/freevrrpd.sh ${DESTDIR}${PREFIX}/share/examples/rc.d
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.8 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man8


.include "../../mk/bsd.pkg.mk"
