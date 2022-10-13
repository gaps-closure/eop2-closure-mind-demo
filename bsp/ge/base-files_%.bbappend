def get_git_hash(d):
  return bb.process.run('git rev-parse --short=8 HEAD')[0].strip('\n')

def get_git_dirty(d):
  dirty = bb.process.run('git status --untracked-files=no --porcelain')
  if dirty[0]:
    return "-dirty"
  else:
    return ""

#PROJ_GIT_HASH = "${@get_git_hash(d)}"
#PROJ_GIT_DIRTY = "${@get_git_dirty(d)}"
#BUILD_ID = "v${MIND_OS_VER}+${PROJ_GIT_HASH}-${DATETIME}${PROJ_GIT_DIRTY}"
BUILD_ID = "v${MIND_OS_VER}-${DATETIME}"
BUILD_ID[vardepsexclude] = "DATETIME"

do_install_append() {
    printf "OS Version: ${DISTRO_NAME} ${DISTRO_VERSION} (${DISTRO_CODENAME}) ${BUILD_ID}\n" > ${D}${sysconfdir}/motd
}

pkg_postinst_ontarget_${PN} () {
  pl-version plver >> /etc/motd
}
