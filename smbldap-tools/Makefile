# $NetBSD: Makefile,v 1.1.1.1 2004/05/18 04:44:33 marmfield Exp $
#

DISTNAME=		smbldap-tools-0.8.4
CATEGORIES=		net sysutils
MASTER_SITES=		http://www.idealx.org/prj/samba/dist/
EXTRACT_SUFX=		.tgz

MAINTAINER=		murray@river-styx.org
HOMEPAGE=		http://www.idealx.org/prj/samba/index.en.html
COMMENT=		Set of ldap administration scripts for samba

DEPENDS+=		samba>=3.0.4:../../net/samba
DEPENDS+=		p5-perl-ldap>=0.30nb1:../../databases/p5-perl-ldap

USE_BUILDLINK3=		yes

REPLACE_PERL=		"smbldap-migrate-accounts"
REPLACE_PERL+=		"smbldap-groupshow"
REPLACE_PERL+=		"smbldap-populate"
REPLACE_PERL+=		"smbldap-useradd"
REPLACE_PERL+=		"smbldap-groupadd"
REPLACE_PERL+=		"smbldap-migrate-groups"
REPLACE_PERL+=		"smbldap-userdel"
REPLACE_PERL+=		"smbldap-groupdel"
REPLACE_PERL+=		"smbldap-usermod"
REPLACE_PERL+=		"smbldap-groupmod"
REPLACE_PERL+=		"smbldap-passwd"
REPLACE_PERL+=		"smbldap-usershow"
REPLACE_PERL+=		"smbldap_tools.pm"
REPLACE_PERL+=		"configure.pl"

SUBST_CLASSES+=		scripts
SUBST_MESSAGE.scripts=	"Fixing directory locations."
SUBST_STAGE.scripts=	do-build
SUBST_FILES.scripts=	configure.pl smbldap_tools.pm smbldap.conf
SUBST_SED.scripts=	-e 's|@PREFIX@|${PREFIX}|g'

SCRIPT_TARGET=		smbldap-groupadd smbldap-groupdel smbldap-groupmod
SCRIPT_TARGET+=		smbldap-groupshow smbldap-migrate-accounts smbldap-migrate-groups
SCRIPT_TARGET+=		smbldap-passwd smbldap-populate smbldap-useradd smbldap-userdel
SCRIPT_TARGET+=		smbldap-usermod smbldap-usershow smbldap_tools.pm

post-extract:
	cd ${WRKSRC} && ${TAR} -zxvf mkntpwd.tar.gz

do-configure:

do-build:
	cd ${WRKSRC}/mkntpwd && ${MAKE}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mkntpwd/mkntpwd ${PREFIX}/sbin;	\
	for PROG in ${SCRIPT_TARGET}; do	\
		${INSTALL_SCRIPT} ${WRKSRC}/$${PROG} ${PREFIX}/sbin;	\
	done
	${INSTALL_DATA_DIR} ${PREFIX}/etc/smbldap-tools;	\
	${INSTALL_DATA} ${WRKSRC}/smbldap.conf ${PREFIX}/etc/smbldap-tools;	\
	${INSTALL_DATA} ${WRKSRC}/smbldap_bind.conf ${PREFIX}/etc/smbldap-tools;	\
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/smbldap-tools;	\
	${INSTALL_DATA} ${WRKSRC}/smbldap.conf ${PREFIX}/share/examples/smbldap-tools;	\
	${INSTALL_DATA} ${WRKSRC}/smbldap_bind.conf ${PREFIX}/share/examples/smbldap-tools;	\
	${WRKSRC}/configure.pl

.include "../../mk/bsd.pkg.mk"
