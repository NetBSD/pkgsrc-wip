# $NetBSD: Makefile,v 1.1 2013/02/02 05:06:43 makoto Exp $
#

DISTNAME=	gdb-7.5
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU:=gdb/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/gdb/gdb.html
COMMENT=	Symbolic debugger for multiple language frontends
LICENSE=	gnu-gpl-v3

#NOT_FOR_PLATFORM=	Darwin-*-* DragonFly-*-* NetBSD-*-x86_64

BROKEN_GETTEXT_DETECTION=	yes
GNU_CONFIGURE=		YES
USE_PKGLOCALEDIR=	YES
USE_LIBTOOL=		YES

USE_TOOLS+=		gmake msgfmt makeinfo
REPLACE_LOCALEDIR_PATTERNS+=	Make-in
INSTALL_TARGET=		install install-info
TEST_TARGET=		check
INFO_FILES=		yes
CONFIGURE_ENV+=		CONFIG_LDFLAGS=${LDFLAGS:M*:Q}

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
# Work around a bug in gdb's configure
CONFIGURE_ENV+=		ac_cv_header_curses_h=yes
.elif ${OPSYS} == "Linux"
USE_TOOLS+=		aclocal autoheader autoconf

pre-configure:
	${RUN} cd ${WRKSRC}/gdb/gdbserver &&				\
	aclocal && autoheader && autoconf

.endif

# pkg_add: Conflicting PLIST with autoconf-2.69nb1: info/standards.info
post-patch:
	${RM} 	${WRKSRC}/etc/standards.info

.include "../../mk/termcap.buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
