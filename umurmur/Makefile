# $NetBSD: Makefile,v 1.1.1.1 2010/10/16 17:09:38 hoka_adam Exp $
#

DISTNAME=	umurmur-0.2.4
CATEGORIES=	comms
MASTER_SITES=	http://umurmur.googlecode.com/files/

MAINTAINER=	ahoka@NetBSD.org
HOMEPAGE=	http://umurmur.googlecode.com/
COMMENT=	Mumble (murmur) server for embedded systems
LICENSE=	3-clause-bsd

WRKSRC=		${WRKDIR}/${DISTNAME}/src
USE_TOOLS+=	gmake
NO_CONFIGURE=	yes

PKG_DESTDIR_SUPPORT=	user-destdir
INSTALLATION_DIRS=	sbin share/examples/umurmur

EGDIR=		${PREFIX}/share/examples/umurmur
CONF_FILES+=	${EGDIR}/umurmur.conf ${PKG_SYSCONFDIR}/umurmur.conf

SUBST_CLASSES+=		conf
SUBST_STAGE.conf=	post-extract
SUBST_FILES.conf=	conf.c
SUBST_SED.conf=	-e 's,/etc/umurmur.conf,${PKG_SYSCONFDIR}/umurmur.conf,g'

RCD_SCRIPTS=	umurmur

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/umurmurd ${DESTDIR}${PREFIX}/sbin
	${INSTALL_DATA} ${WRKSRC}/../umurmur.conf.example \
		${DESTDIR}${EGDIR}/umurmur.conf

.include "../../devel/libconfig/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
