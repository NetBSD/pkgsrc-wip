# $NetBSD: Makefile,v 1.4 2013/01/13 00:42:39 wongk Exp $
#

DISTNAME=	umurmur-0.2.10
CATEGORIES=	comms
MASTER_SITES=	http://umurmur.googlecode.com/files/

MAINTAINER=	ahoka@NetBSD.org
HOMEPAGE=	http://umurmur.googlecode.com/
COMMENT=	Mumble (murmur) server for embedded systems
LICENSE=	3-clause-bsd

USE_TOOLS+=	gmake
GNU_CONFIGURE=	yes

LDFLAGS.SunOS+= -lresolv -lsocket -lnsl

INSTALLATION_DIRS=	sbin share/examples/umurmur

EGDIR=		${PREFIX}/share/examples/umurmur
CONF_FILES+=	${EGDIR}/umurmur.conf ${PKG_SYSCONFDIR}/umurmur.conf

SUBST_CLASSES+=		conf
SUBST_STAGE.conf=	post-extract
SUBST_FILES.conf=	src/conf.*
SUBST_SED.conf=	-e 's,/etc/umurmur.conf,${PKG_SYSCONFDIR}/umurmur.conf,g'

SUBST_CLASSES+=		certdir
SUBST_STAGE.certdir=	post-extract
SUBST_FILES.certdir=	umurmur.conf.example
SUBST_SED.certdir=	-e 's,/etc,${PKG_SYSCONFDIR},g'

MAKE_DIRS+=	${PKG_SYSCONFDIR}/umurmur
RCD_SCRIPTS=	umurmur

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/umurmurd ${DESTDIR}${PREFIX}/sbin
	${INSTALL_DATA} ${WRKSRC}/umurmur.conf.example \
		${DESTDIR}${EGDIR}/umurmur.conf

.include "../../devel/libconfig/buildlink3.mk"
.include "../../wip/protobuf-c/buildlink3.mk"
.include "../../wip/polarssl11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
