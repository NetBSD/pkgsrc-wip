# $NetBSD: Makefile,v 1.10 2007/01/31 13:52:40 marmfield Exp $

DISTNAME=	smbldap-tools-0.9.2a
CATEGORIES=	sysutils net databases
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=smbldap-tools/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	murray@river-styx.org
HOMEPAGE=	http://sourceforge.net/projects/smbldap-tools/
COMMENT=	Set of ldap administration scripts for samba

DEPENDS+=	samba>=3.0.22:../../net/samba
DEPENDS+=	p5-perl-ldap>=0.33:../../databases/p5-perl-ldap
DEPENDS+=	p5-Crypt-SmbHash>=0.12:../../security/p5-Crypt-SmbHash
DEPENDS+=	p5-Digest-SHA1>=2.11:../../security/p5-Digest-SHA1
DEPENDS+=	p5-Unicode-MapUTF8-[0-9]*:../../wip/p5-Unicode-MapUTF8

WRKSRC=		${WRKDIR}/smbldap-tools-0.9.2

NO_BUILD=	yes

USE_TOOLS+=	perl:run

REPLACE_PERL=	configure.pl
REPLACE_PERL+=	smbldap-groupadd
REPLACE_PERL+=	smbldap-groupdel
REPLACE_PERL+=	smbldap-groupmod
REPLACE_PERL+=	smbldap-groupshow
REPLACE_PERL+=	smbldap-passwd
REPLACE_PERL+=	smbldap-populate
REPLACE_PERL+=	smbldap-useradd
REPLACE_PERL+=	smbldap-userdel
REPLACE_PERL+=	smbldap-userinfo
REPLACE_PERL+=	smbldap-usermod
REPLACE_PERL+=	smbldap-usershow
REPLACE_PERL+=	smbldap_tools.pm
REPLACE_PERL+=	doc/smbldap-migrate-pwdump-accounts
REPLACE_PERL+=	doc/smbldap-migrate-pwdump-groups
REPLACE_PERL+=	doc/smbldap-migrate-unix-accounts
REPLACE_PERL+=	doc/smbldap-migrate-unix-groups

SUBST_CLASSES+=		conf
SUBST_STAGE.conf=	post-patch
SUBST_FILES.conf=	configure.pl smbldap_tools.pm smbldap.conf
SUBST_SED.conf=		-e "s,@PREFIX@,${PREFIX},g"

EGDIR=			${PREFIX}/share/examples/smbldap-tools
CONFS=			smbldap.conf smbldap_bind.conf

.for afile in ${CONFS}
CONF_FILES+=		${EGDIR}/${afile} ${PKG_SYSCONFDIR}/smbldap-tools/${afile}
.endfor

pre-install:
	${RM} ${WRKSRC}/smbldap*.orig
	${RM} ${WRKSRC}/smbldap-tools.spec
	${INSTALL_DATA_DIR} ${PREFIX}/etc/smbldap-tools
	${INSTALL_DATA_DIR} ${PREFIX}/share/smbldap-tools

post-install:
	${INSTALL_DATA} ${WRKSRC}/configure.pl ${PREFIX}/share/smbldap-tools
	${INSTALL_DATA} ${WRKSRC}/doc/smbldap-* ${PREFIX}/share/smbldap-tools

.include "../../mk/bsd.pkg.mk"
