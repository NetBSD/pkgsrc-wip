# $NetBSD: Makefile,v 1.13 2014/06/01 12:49:37 thomasklausner Exp $

DISTNAME=		pam_pkcs11-0.6.8
PKGNAME=		pam-pkcs11-0.6.8
CATEGORIES=		security
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=opensc/}pam_pkcs11/
#http://sourceforge.net/projects/opensc/files/pam_pkcs11/

MAINTAINER=		gdt@ir.bbn.com
# Did not answer mail 2011-11
#MAINTAINER=		evaldo@gardenali.biz
HOMEPAGE=		https://github.com/OpenSC/pam_pkcs11/wiki
COMMENT=		PKCS \#11 authentication method for PAM
LICENSE=		gnu-lgpl-v2.1

# At times in the past, pam_pkcs11 has been https

USE_LANGUAGES=		c99
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config

EGDIR=			${PREFIX}/share/examples/pam-pkcs11
PKG_SYSCONFSUBDIR=	pam-pkcs11
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--docdir=${EGDIR}

.include "../../mk/bsd.prefs.mk"

.include "options.mk"
PLIST_SRC+=		PLIST.common

# See TODO.
USE_TOOLS+=		bash:run
REPLACE_INTERPRETER+=	bash
REPLACE.bash.old=	.*/bin/bash
REPLACE.bash.new=	${PREFIX}/bin/bash
REPLACE_FILES.bash=	tools/pkcs11_make_hash_link

CONF_FILES+=	${EGDIR}/card_eventmgr.conf.example ${PKG_SYSCONFDIR}/card_eventmgr.conf.example
CONF_FILES+=	${EGDIR}/digest_mapping.example ${PKG_SYSCONFDIR}/digest_mapping.example
CONF_FILES+=	${EGDIR}/mail_mapping.example ${PKG_SYSCONFDIR}/mail_mapping.example
CONF_FILES+=	${EGDIR}/pam.d_login.example ${PKG_SYSCONFDIR}/pam.d_login.example
CONF_FILES+=	${EGDIR}/pam_pkcs11.conf.example ${PKG_SYSCONFDIR}/pam_pkcs11.conf.example
CONF_FILES+=	${EGDIR}/pkcs11_eventmgr.conf.example ${PKG_SYSCONFDIR}/pkcs11_eventmgr.conf.example
CONF_FILES+=	${EGDIR}/subject_mapping.example ${PKG_SYSCONFDIR}/subject_mapping.example

.include "../../mk/pam.buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
