# $NetBSD: Makefile,v 1.4 2006/09/28 21:47:31 elge Exp $
#

DISTNAME=		postoffice-1.3.4
CATEGORIES=		mail
MASTER_SITES=		http://www.tsfr.org/~orc/Code/postoffice/

MAINTAINER=		pbraun@nethence.com
HOMEPAGE=		http://www.tsfr.org/~orc/Code/postoffice/
COMMENT=		Simple greylist, auth, milter, virtual hosts mbox capable SMTP server

HAS_CONFIGURE=yes
CONFIGURE_SCRIPT=./configure.sh
CONFIGURE_ARGS+=--prefix=${PREFIX}
CONFIGURE_ARGS+=--use-mailwrappers
INSTALLATION_DIRS+=${PREFIX}/share/examples/postoffice
INSTALLATION_DIRS+=${PREFIX}/share/examples/rc.d
RCD_SCRIPTS+=postoffice

BUILD_DEFS+=POSTOFFICE_AUTH
BUILD_DEFS+=POSTOFFICE_GREYLIST
BUILD_DEFS+=POSTOFFICE_MILTER
BUILD_DEFS+=POSTOFFICE_TCPWRAPPERS
BUILD_DEFS+=POSTOFFICE_VIRTUAL

.if defined(POSTOFFICE_TCPWRAPPERS) && !empty(POSTOFFICE_TCPWRAPPERS:M[Yy][Ee][Ss])
CONFIGURE_ARGS+=--with-tcpwrappers
.  endif
.if defined(POSTOFFICE_GREYLIST) && !empty(POSTOFFICE_GREYLIST:M[Yy][Ee][Ss])
CONFIGURE_ARGS+=--with-greylist
.  endif
.if defined(POSTOFFICE_AUTH) && !empty(POSTOFFICE_AUTH:M[Yy][Ee][Ss])
CONFIGURE_ARGS+=--with-auth
.  endif
.if defined(POSTOFFICE_MILTER) && !empty(POSTOFFICE_MILTER:M[Yy][Ee][Ss])
CONFIGURE_ARGS+=--with-milter
.  endif
.if defined(POSTOFFICE_VIRTUAL) && !empty(POSTOFFICE_VIRTUAL:M[Yy][Ee][Ss])
CONFIGURE_ARGS+=--with-vhost=/etc/virtual \
	--with-vspool=/var/spool/virtual \
	--with-vuser=mail
.  endif

post-install:
	${INSTALL_DATA} ${FILESDIR}/postoffice.cf ${PREFIX}/share/examples/postoffice

.include "../../mk/bsd.pkg.mk"
