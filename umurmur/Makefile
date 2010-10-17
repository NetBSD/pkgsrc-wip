# $NetBSD: Makefile,v 1.2 2010/10/17 08:49:14 hoka_adam Exp $
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

SUBST_CLASSES+=		certdir
SUBST_STAGE.certdir=	post-extract
SUBST_FILES.certdir=	../umurmur.conf.example
SUBST_SED.certdir=	-e 's,/etc,${PKG_SYSCONFDIR},g'

MAKE_DIRS+=	${PKG_SYSCONFDIR}/umurmur
RCD_SCRIPTS=	umurmur

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/umurmurd ${DESTDIR}${PREFIX}/sbin
	${INSTALL_DATA} ${WRKSRC}/../umurmur.conf.example \
		${DESTDIR}${EGDIR}/umurmur.conf

.include "../../devel/libconfig/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
