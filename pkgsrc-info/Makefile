# $NetBSD$

DISTNAME=	pkgsrc-info-1
CATEGORIES=	pkgtools
DISTFILES=	# none

MAINTAINER=	kikadf.01@gmail.com
HOMEPAGE=	https://www.NetBSD.org/docs/pkgsrc/
COMMENT=	Small tool to display basic information about the pkgsrc tree
LICENSE=	2-clause-bsd

.include "../../mk/bsd.prefs.mk"
.include "../../mk/krb5.buildlink3.mk"
.include "../../lang/lua/luaversion.mk"
.include "../../lang/go/version.mk"
PYTHON_FOR_BUILD_ONLY=	yes
.include "../../lang/python/pyversion.mk"
.include "../../lang/php/phpversion.mk"
.include "../../lang/ruby/rubyversion.mk"

HOSTNAME=	${UNAME} -n
BUILD_DEFS+=	JPEG_DEFAULT EMACS_TYPE LIBUSB_TYPE

SUBST_CLASSES+=		files
SUBST_STAGE.files=	pre-configure
SUBST_MESSAGE.files=	Set variables in pkgsrc-info
SUBST_FILES.files+=	pkgsrc-info.sh.in
SUBST_SED.files+=	-e 's,@HOST@,${OPSYS} ${OS_VERSION} ${MACHINE_ARCH},g'
SUBST_SED.files+=	-e 's,@HOSTNAME@,${HOSTNAME:sh},g'
SUBST_SED.files+=	-e 's,@X11@,${X11_TYPE},g'
SUBST_SED.files+=	-e 's,@JPEG@,${JPEG_DEFAULT},g'
SUBST_SED.files+=	-e 's,@LUA@,${LUA_VERSION_DEFAULT},g'
SUBST_SED.files+=	-e 's,@GO@,${GO_VERSION_DEFAULT},g'
SUBST_SED.files+=	-e 's,@EMACS@,${EMACS_TYPE},g'
SUBST_SED.files+=	-e 's,@LIBUSB@,${LIBUSB_TYPE},g'
SUBST_SED.files+=	-e 's,@KRB5@,${KRB5_DEFAULT},g'
SUBST_SED.files+=	-e 's,@PYTHON@,${PYTHON_VERSION_DEFAULT},g'
SUBST_SED.files+=	-e 's,@PHP@,${PHP_VERSION_DEFAULT},g'
SUBST_SED.files+=	-e 's,@RUBY@,${RUBY_VERSION_DEFAULT},g'

.include "options.mk"

.if !empty(PKG_OPTIONS:Mjava)
SUBST_SED.files+=	-e 's,@JVM@,${_PKG_JVM_DEFAULT},g'
.else
SUBST_SED.files+=	-e 's,@JVM@,Not checked,g'
.endif

.if !empty(PKG_OPTIONS:Mrust)
SUBST_SED.files+=	-e 's,@RUST@,${RUST_TYPE},g'
.else
SUBST_SED.files+=	-e 's,@RUST@,Not checked,g'
.endif

TOOL_DEPENDS+=	git-base-[0-9]*:../../devel/git-base
TOOL_DEPENDS+=	${PYPKGPREFIX}-mercurial-[0-9]*:../../devel/py-mercurial

WRKSRC=			${WRKDIR}
INSTALLATION_DIRS+=	bin

do-extract:
	${CP} ${FILESDIR}/pkgsrc-info.sh.in ${WRKSRC}

do-build:
	cd ${FILESDIR} && \
		${SH} ./get_pkgsrc_infos.sh || ${FALSE}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/pkgsrc-info.sh ${DESTDIR}${PREFIX}/bin/pkgsrc-info

.include "../../mk/bsd.pkg.mk"
