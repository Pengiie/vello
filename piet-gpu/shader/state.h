// Code auto-generated by piet-gpu-derive

struct StateRef {
    uint offset;
};

struct State {
    vec4 mat;
    vec2 translate;
    vec4 bbox;
    float linewidth;
    uint flags;
};

#define State_size 48

StateRef State_index(StateRef ref, uint index) {
    return StateRef(ref.offset + index * State_size);
}

State State_read(StateRef ref) {
    uint ix = ref.offset >> 2;
    uint raw0 = state[ix + 0];
    uint raw1 = state[ix + 1];
    uint raw2 = state[ix + 2];
    uint raw3 = state[ix + 3];
    uint raw4 = state[ix + 4];
    uint raw5 = state[ix + 5];
    uint raw6 = state[ix + 6];
    uint raw7 = state[ix + 7];
    uint raw8 = state[ix + 8];
    uint raw9 = state[ix + 9];
    uint raw10 = state[ix + 10];
    uint raw11 = state[ix + 11];
    State s;
    s.mat = vec4(uintBitsToFloat(raw0), uintBitsToFloat(raw1), uintBitsToFloat(raw2), uintBitsToFloat(raw3));
    s.translate = vec2(uintBitsToFloat(raw4), uintBitsToFloat(raw5));
    s.bbox = vec4(uintBitsToFloat(raw6), uintBitsToFloat(raw7), uintBitsToFloat(raw8), uintBitsToFloat(raw9));
    s.linewidth = uintBitsToFloat(raw10);
    s.flags = raw11;
    return s;
}

void State_write(StateRef ref, State s) {
    uint ix = ref.offset >> 2;
    state[ix + 0] = floatBitsToUint(s.mat.x);
    state[ix + 1] = floatBitsToUint(s.mat.y);
    state[ix + 2] = floatBitsToUint(s.mat.z);
    state[ix + 3] = floatBitsToUint(s.mat.w);
    state[ix + 4] = floatBitsToUint(s.translate.x);
    state[ix + 5] = floatBitsToUint(s.translate.y);
    state[ix + 6] = floatBitsToUint(s.bbox.x);
    state[ix + 7] = floatBitsToUint(s.bbox.y);
    state[ix + 8] = floatBitsToUint(s.bbox.z);
    state[ix + 9] = floatBitsToUint(s.bbox.w);
    state[ix + 10] = floatBitsToUint(s.linewidth);
    state[ix + 11] = s.flags;
}

