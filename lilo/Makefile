# $NetBSD: Makefile,v 1.4 2005/05/24 10:30:42 rillig Exp $

DISTNAME=		lilo-22.5.9
CATEGORIES=		sysutils
MASTER_SITES=		${MASTER_SITE_SUNSITE:=system/boot/lilo/}

MAINTAINER=		reed@reedmedia.net
HOMEPAGE=		http://lilo.go.dyndns.org/
COMMENT=		Generic boot loader for Linux

# This is LInux LOader; it can load different operating systems.
# Build untested on other operating systems.
ONLY_FOR_PLATFORM=	Linux-*-*

# Don't force perl for extra tool -- maybe a MESSAGE?
#USE_PERL5=		YES

# bin86 builds under Linux but not NetBSD, and
# bcc builds under NetBSD, but not Linux -- both need to be fixed
#BUILD_DEPENDS+=		bcc>=95.3.12:../../devel/bcc
BUILD_DEPENDS+=		bin86>=0.16.9:../../wip/bin86
BUILD_DEPENDS+=		nasm>=0.98:../../devel/nasm

USE_TOOLS+=		gmake
MAKE_ENV+=		ROOT=${PREFIX}
MAKE_ENV+=		SYSCONFDIR=${PKG_SYSCONFDIR}
PKGMANDIR?=		man
MAKE_ENV+=		PKGMANDIR+=${PKGMANDIR}

MAKE_COMMAND=		${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} ${MAKE_FLAGS}

USE_PKGINSTALL=		YES

CONF_FILES=		${PREFIX}/share/lilo/lilo.conf.example	${PKG_SYSCONFDIR}/lilo.conf

REPLACE_INTERPRETER+=	bash
_REPLACE.bash.old=	.*/bin/bash
_REPLACE.bash.new=	${SH}
_REPLACE_FILES.bash=	mkrescue

REPLACE_INTERPRETER+=	perl
_REPLACE.perl.old=	.*/bin/perl
_REPLACE.perl.new=	${PERL5}
_REPLACE_FILES.perl=	keytab-lilo.pl

post-patch:
	${CP} ${WRKSRC}/config.h ${WRKSRC}/config.h.orig
	${SED} -e "s:@@PREFIX@@:${PREFIX}:" \
		-e "s:@@PKG_SYSCONFDIR@@:${PKG_SYSCONFDIR}:" \
		< ${WRKSRC}/config.h.orig > ${WRKSRC}/config.h

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/lilo ${PREFIX}/sbin/lilo
	${INSTALL_SCRIPT} ${WRKSRC}/mkrescue ${PREFIX}/sbin/mkrescue
	${INSTALL_SCRIPT} ${WRKSRC}/keytab-lilo.pl ${PREFIX}/sbin/keytab-lilo
	${INSTALL_MAN} ${WRKSRC}/manPages/lilo.8 ${PREFIX}/${PKGMANDIR}/man8
	${INSTALL_MAN} ${WRKSRC}/manPages/lilo.conf.5 ${PREFIX}/${PKGMANDIR}/man5
	${INSTALL_MAN} ${WRKSRC}/manPages/mkrescue.8 ${PREFIX}/${PKGMANDIR}/man8
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/lilo
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/lilo
	${INSTALL_DATA_DIR} ${PREFIX}/share/lilo
	${INSTALL_DATA} ${WRKSRC}/sample/lilo.sample.conf ${PREFIX}/share/lilo
	${INSTALL_DATA} ${FILESDIR}/lilo.conf.example ${PREFIX}/share/lilo

.include "../../mk/bsd.pkg.mk"
