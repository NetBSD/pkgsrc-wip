# $NetBSD: Makefile,v 1.4 2005/06/20 07:00:35 marmfield Exp $
#

DISTNAME=		smbldap-tools-0.9.1
CATEGORIES=		sysutils net databases
MASTER_SITES=		http://www.idealx.org/prj/samba/dist/
EXTRACT_SUFX=		.tgz

MAINTAINER=		murray@river-styx.org
HOMEPAGE=		http://www.idealx.org/prj/samba/index.en.html
COMMENT=		Set of ldap administration scripts for samba

DEPENDS+=		samba>=3.0.14anb1:../../net/samba
DEPENDS+=		p5-perl-ldap>=0.32.02:../../databases/p5-perl-ldap
DEPENDS+=		p5-Crypt-SmbHash>=0.12:../../wip/p5-Crypt-SmbHash

EGDIR=			${PREFIX}/share/examples/smbldap-tools
CONFS=			smbldap.conf smbldap_bind.conf

.for FILE in ${CONFS}
CONF_FILES+=		${EGDIR}/${FILE} ${PKG_SYSCONFDIR}/${FILE}
.endfor

REPLACE_PERL=		"smbldap-groupadd"
REPLACE_PERL+=		"smbldap-groupdel"
REPLACE_PERL+=		"smbldap-groupmod"
REPLACE_PERL+=		"smbldap-groupshow"
REPLACE_PERL+=		"smbldap-passwd"
REPLACE_PERL+=		"smbldap-populate"
REPLACE_PERL+=		"smbldap-useradd"
REPLACE_PERL+=		"smbldap-userdel"
REPLACE_PERL+=		"smbldap-userinfo"
REPLACE_PERL+=		"smbldap-usermod"
REPLACE_PERL+=		"smbldap-usershow"
REPLACE_PERL+=		"smbldap_tools.pm"
REPLACE_PERL+=		"configure.pl"
REPLACE_PERL+=		"doc/smbldap-migrate-pwdump-accounts"
REPLACE_PERL+=		"doc/smbldap-migrate-pwdump-groups"
REPLACE_PERL+=		"doc/smbldap-migrate-unix-accounts"
REPLACE_PERL+=		"doc/smbldap-migrate-unix-groups"

SUBST_CLASSES+=		scripts
SUBST_MESSAGE.scripts=	"Fixing directory locations."
SUBST_STAGE.scripts=	do-configure
SUBST_FILES.scripts=	configure.pl smbldap_tools.pm
SUBST_FILES.scripts+=	smbldap.conf smbldap-populate
SUBST_SED.scripts=	-e 's|@PREFIX@|${PREFIX}|g'

do-build:

pre-install:
	${RM} ${WRKSRC}/smbldap*.orig

post-install:
	${MKDIR} ${PREFIX}/share/smbldap-tools
	${CP} ${WRKSRC}/configure.pl ${PREFIX}/share/smbldap-tools
	${CP} ${WRKSRC}/doc/smbldap-* ${PREFIX}/share/smbldap-tools
	${RM} ${PREFIX}/sbin/smbldap-tools.spec

.include "../../mk/bsd.pkg.mk"
