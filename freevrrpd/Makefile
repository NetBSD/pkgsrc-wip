# $Id: Makefile,v 1.6 2006/04/20 13:36:36 cheusov Exp $
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

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/freevrrpd ${PREFIX}/sbin
	${INSTALL_DATA} ${WRKSRC}/freevrrpd.conf.sample ${PREFIX}/etc
	${INSTALL_SCRIPT} ${FILESDIR}/freevrrpd.sh ${PREFIX}/etc/rc.d
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.8 ${PREFIX}/${PKGMANDIR}/man8


.include "../../mk/bsd.pkg.mk"
