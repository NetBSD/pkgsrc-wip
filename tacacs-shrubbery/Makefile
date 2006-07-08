# $NetBSD: Makefile,v 1.1.1.1 2006/07/08 20:50:15 gschwarz Exp $
#

DISTNAME=	tacacs+-F4.0.4.10
PKGNAME=	${DISTNAME:S,tacacs+,tacacs,}
CATEGORIES=	net security
MASTER_SITES=	ftp://ftp.shrubbery.net/pub/tac_plus/

MAINTAINER=	schwarz@NetBSD.org
HOMEPAGE=	http://www.shrubbery.net/tac_plus/
COMMENT=	Cisco AAA protocol (tacacs+) daemon (Shrubbery Networks version)

.include "options.mk"

GNU_CONFIGURE=	yes
USE_TOOLS+=	perl

CONFIGURE_ARGS+=	--with-libwrap=${BUILDLINK_PREFIX.tcp_wrappers}
CONFIGURE_ARGS+=	--with-skey=${BUILDLINK_PREFIX.skey}

INSTALLATION_DIRS=	sbin ${PKGMANDIR}/man3 ${PKGMANDIR}/man5 \
			${PKGMANDIR}/man8 share/doc/tacacs

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tac_plus ${WRKSRC}/tac_pwd \
	${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/regexp.3 ${PREFIX}/${PKGMANDIR}/man3
	${INSTALL_MAN} ${WRKSRC}/tac_plus.conf.5 ${PREFIX}/${PKGMANDIR}/man5
	${INSTALL_MAN} ${WRKSRC}/tac_plus.8 ${WRKSRC}/tac_pwd.8 \
	${PREFIX}/${PKGMANDIR}/man8
	${INSTALL_DATA} ${WRKSRC}/users_guide ${PREFIX}/share/doc/tacacs

.include "../../security/skey/buildlink3.mk"
.include "../../security/tcp_wrappers/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
