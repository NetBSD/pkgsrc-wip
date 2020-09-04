# $NetBSD: Makefile,v 1.4 2012/10/03 15:09:49 asau Exp $

DISTNAME=		majordomo-20060817
PKGNAME=		majordomo-devel-20060817
PKGREVISION=		1
CATEGORIES=		mail
MASTER_SITES=		http://ftp.mj2.org/pub/mj2/snapshots/2006-08/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.mj2.org/
COMMENT=		The Majordomo mailing list manager, version 2

# Mail::Internet>=1.30, Mail::Header>=1.10
DEPENDS+=	p5-MailTools>=1.67:../../mail/p5-MailTools
# IO::Wrap>=1.101
DEPENDS+=	p5-IO-stringy>=2.108:../../devel/p5-IO-stringy
DEPENDS+=	p5-MIME-tools>=4.119:../../mail/p5-MIME-tools
DEPENDS+=	p5-Date-Manip>=5.10:../../devel/p5-Date-Manip
DEPENDS+=	p5-Digest-SHA1-[0-9]*:../../security/p5-Digest-SHA1
# Date::Format>=2.20, Date::Parse
DEPENDS+=	p5-TimeDate>=1.15:../../time/p5-TimeDate
DEPENDS+=	p5-HTML-Format-[0-9]*:../../www/p5-HTML-Format
DEPENDS+=	p5-HTML-Tree-[0-9]*:../../www/p5-HTML-Tree
# optional
DEPENDS+=	p5-Text-Reflow>=1.04:../../textproc/p5-Text-Reflow
# Support for MySQL/PostgreSQL is experimental in MJ2
#DEPENDS+=	p5-DBI>=1.28:../../databases/p5-DBI
#DEPENDS+=	p5-DBD-postgresql>=1.13:../../databases/p5-DBD-postgresql
#DEPENDS+=	p5-DBD-mysql>=2.1010:../../databases/p5-DBD-mysql

## builtin to perl>=5.8
##DEPENDS+=	p5-MIME-Base64>=2.00:../../converters/p5-MIME-Base64
##DEPENDS+=	p5-CGI>=2.36:../../www/p5-CGI
## Net::Domain
##DEPENDS+=	p5-Net-[0-9]*:../../net/p5-Net
##DEPENDS+=	p5-Time-Local-[0-9]*:../../time/p5-Time-Local
# optional
##DEPENDS+=	p5-Time-HiRes-[0-9]*:../../time/p5-Time-HiRes
##DEPENDS+=	p5-DB_File>=1.63:../../databases/p5-DB_File


WRKSRC=			${WRKDIR}/majordomo

INTERACTIVE_STAGE=	install

USE_TOOLS+=		perl:run

SUBST_CLASSES+=		mj2
SUBST_STAGE.mj2=	pre-configure
SUBST_FILES.mj2=	.mj_config
SUBST_MESSAGE.mj2=	Setting values in .mj_config
SUBST_SED.mj2+=		-e s,@@MJ2_INSTALL_DIR@@,${MJ2_INSTALL_DIR},
SUBST_SED.mj2+=		-e s,@@MJ2_SYSCONFDIR@@,${MJ2_SYSCONFDIR},
SUBST_SED.mj2+=		-e s,@@MJ2_LISTDIR@@,${MJ2_LISTDIR},
SUBST_SED.mj2+=		-e s,@@MJ2_SEC_TMPDIR@@,${MJ2_SEC_TMPDIR},
SUBST_SED.mj2+=		-e s,@@MJ2_LOCKDIR@@,${MJ2_LOCKDIR},
SUBST_SED.mj2+=		-e s,@@MJ2_PERL5@@,${MJ2_PERL5},
SUBST_SED.mj2+=		-e s,@@MJ2_USER@@,${MJ2_USER},
SUBST_SED.mj2+=		-e s,@@MJ2_GROUP@@,${MJ2_GROUP},
SUBST_SED.mj2+=		-e s,@@MJ2_UMASK@@,${MJ2_UMASK},
SUBST_SED.mj2+=		-e s,@@MJ2_IGNORE_CASE@@,${MJ2_IGNORE_CASE},
SUBST_SED.mj2+=		-e s,@@MJ2_DB_BACKEND@@,${MJ2_DB_BACKEND},
SUBST_SED.mj2+=		-e s,@@MJ2_OS_REAPS_CHILDS@@,${MJ2_OS_REAPS_CHILDS},
SUBST_SED.mj2+=		-e s,@@MJ2_QMAIL_BINDIR@@,${MJ2_QMAIL_BINDIR},

REPLACE_PERL+=		convertdb.pl convertlist.pl

PKG_GROUPS+=		${MJ2_GROUP}
PKG_USERS+=		${MJ2_USER}:${MJ2_GROUP}

PKG_SYSCONFSUBDIR=	majordomo

REQD_DIRS+=		${MJ2_INSTALL_DIR} ${MJ2_LISTDIR}
OWN_DIRS+=		${MJ2_INSTALL_DIR}/scripts ${MJ2_LISTDIR}/LIB

OWN_DIRS_PERMS+=	${VARBASE}/majordomo ${MJ2_USER} ${MJ2_GROUP} 0700
OWN_DIRS_PERMS+=	${MJ2_SEC_TMPDIR} ${MJ2_USER} ${MJ2_GROUP} 0700
OWN_DIRS_PERMS+=	${MJ2_LOCKDIR} ${MJ2_USER} ${MJ2_GROUP} 0700

PLIST_SRC=		PLIST.${MJ2_MTA}

# XXX possible values: exim, postfix, qmail, sendmail
# should probably be an option
MJ2_MTA=		postfix

MJ2_INSTALL_DIR=	${PREFIX}/majordomo
MJ2_SYSCONFDIR=		${PKG_SYSCONFDIR}
MJ2_LISTDIR=		${MJ2_INSTALL_DIR}/lists
MJ2_SEC_TMPDIR=		${VARBASE}/majordomo/tmp
MJ2_LOCKDIR=		${MJ2_SEC_TMPDIR}/locks
MJ2_PERL5=		${PERL5}
MJ2_USER=		mjdomo2
MJ2_GROUP=		mjdomo2
MJ2_UMASK=		077
MJ2_IGNORE_CASE=	1
MJ2_DB_BACKEND=		db
MJ2_OS_REAPS_CHILDS=	1
MJ2_QMAIL_BINDIR=	/var/qmail/bin

#INSTALL_MAKE_FLAGS+=	VERBOSE=1
INSTALL_MAKE_FLAGS+=	QUIET=1
#INSTALL_MAKE_FLAGS+=	ASK=1
#INSTALL_MAKE_FLAGS+=	SKIP=1

TEST_TARGET=		test

post-extract:
	${CAT} ${FILESDIR}/mj_config.common ${FILESDIR}/mj_config.${MJ2_MTA} > \
	  ${WRKSRC}/.mj_config

do-configure:
	cd ${WRKSRC} && { ${ECHO};${ECHO};${ECHO};${ECHO}; } | ${PERL5} Makefile.PL

.include "../../mk/bsd.pkg.mk"
